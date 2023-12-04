const getSumAbsoluteDifferences = (nums: number[]): number[] => 
{
    // Hold the suffix sum
    let suffixSum: number = 0;

    // Hold the prefix sum
    let prefixSum: number = 0;

    // Loop through the nums to get the suffix sum
    for(let counter: number = nums.length - 1; counter > 0; counter--)
    {
            
        // Add the value
        suffixSum += nums[counter];
    }

    // Loop through the nums again populating the solution vector
    for(let counter: number = 0; counter < nums.length; counter++)
    {

        // Hold the current value
        let currentValue: number = nums[counter];

        // Hold the amount of elements to the left
        let elementsToLeft: number = counter;

        // Hold the amount of elements to the right
        let elementsToRight: number = nums.length - counter - 1;

        // Hold the answer for the left side
        let leftSideAnswer: number = elementsToLeft * currentValue - prefixSum;

        // Hold the answer for the right side
        let rightSideAnswer: number = suffixSum - elementsToRight * currentValue;

        // Push the resulting sum to the solution
        nums[counter] = leftSideAnswer + rightSideAnswer;

        // Increment prefix sum
        prefixSum += currentValue;

        // Check if the counter is out of bounds
        if(counter + 1 < nums.length)
        {

            // Decrement the suffix sum
            suffixSum -= nums[counter + 1];
        }
    }

    // Return the solution
    return nums;
}