#include <iostream>
#include <vector>

vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
{
    // Hold the suffix sum
    int suffixSum = 0;

    // Hold the prefix sum
    int prefixSum = 0;

    // Loop through the nums to get the suffix sum
    for(int counter = nums.size()-1; counter > 0; counter--)
    {

        // Add the value
        suffixSum += nums[counter];
    }

    // Loop through the nums again populating the solution vector
    for(int counter = 0; counter < nums.size(); counter++)
    {

        // Hold the current value
        int currentValue = nums[counter];

        // Hold the amount of elements to the left
        int elementsToLeft = counter;

        // Hold the amount of elements to the right
        int elementsToRight = nums.size() - counter -1;

        // Hold the answer for the left side
        int leftSideAnswer = elementsToLeft * currentValue - prefixSum;

        // Hold the answer for the right side
        int rightSideAnswer = suffixSum - elementsToRight * currentValue;

        // Push the resulting sum to the solution
        nums[counter] = leftSideAnswer + rightSideAnswer;

        // Increment prefix sum
        prefixSum += currentValue;

        // Check if the counter is out of bounds
        if(counter + 1 < nums.size())
        {

            // Decrement the suffix sum
            suffixSum -= nums[counter + 1];
        }
    }

    // Return the solution
    return nums;
}

