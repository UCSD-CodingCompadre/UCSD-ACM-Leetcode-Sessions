/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, 
if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. 
If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/
function nextPermutation(nums: number[]): void 
{

    // Hold the first pointer
    let pointer1: number = nums.length-1;

    // Loop until we reach the first index
    while(pointer1 > 0)
    {

        // Check for location when descendingorder stops
        if(nums[pointer1] > nums[pointer1-1])
        {

            // Break from the loop
            break;
        }

        // Decrement the pointer
        pointer1--;
    }

    // Decrement the pointer to index we need to swap
    pointer1--;

    // Check for the edge case when we reached the last permuation and need to reverse the array
    if(pointer1 == -1)
    {
        
        // Reverse the entire array
        reverse(0, nums.length-1, nums)
        
        // Exit the function
        return;
    }

    // Loop through the array until the first pointer
    for(let pointer2: number = nums.length-1; pointer2 >= pointer1; pointer2--)
    {

         // Check once we found a value greater than the value we need to swap
        if(nums[pointer2] > nums[pointer1])
        {

            // Swap the values
            swap(pointer1, pointer2, nums);
            
            // Break from the loop
            break;
        }
    }

    // Reverse the rest of the array that is in descending order
    reverse(pointer1+1, nums.length-1, nums);

    // Exit the function
    return;
};

const swap = (leftPointer: number, rightPointer: number, nums: number[]) =>
{

    // Hold the temp value
    const temp: number = nums[leftPointer];

    // Swap the value with the left pointer
    nums[leftPointer] = nums[rightPointer];

    // Swap the value using the temp value
    nums[rightPointer] = temp;
} 

const reverse = (leftPointer: number, rightPointer: number, nums: number[]) =>
{

    // Loop until the pointers meet in the middle
    while(leftPointer < rightPointer)
    {

        // Swap the elements in the array
        swap(leftPointer, rightPointer, nums);

        // Increment the left pointer
        leftPointer++;

        // Decrement the right pointer
        rightPointer--;
    }
}