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

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums) 
{

    // Hold the first pointer
    int pointer1 = nums.size()-1;

    // Loop until we reach the end of the vector
    while(pointer1 > 0)
    {

        // Check if the vector stop's descending order
        if(nums[pointer1] > nums[pointer1-1])
        {

            // Break from the loop
            break;
        }

        // Decrement the pointer
        pointer1--;
    }

    // Decrement the pointer to reach the location to start swapping
    pointer1--;

    // Check for the edge case when we reached the last permuation and need to reverse the array
    if(pointer1 == -1)
    {

        // Reverse the whole vector
        reverse(nums.begin(), nums.end());
        
        // Exit the function
        return;
    }

    // Loop through the vector until the first pointer
    for(int pointer2 = nums.size()-1; pointer2 >= pointer1; pointer2--)
    {

        // Check once we found a value greater than the value we need to swap
        if(nums[pointer2] > nums[pointer1])
        {

            // Swap the numbers
            swap(nums[pointer1], nums[pointer2]);

            // Break from the loop
            break;
        }
    }

    // Now we can reverse the rest of the vector since it should be descending order
    reverse(nums.begin()+pointer1+1, nums.end());

    // Exit the function
    return;
}

