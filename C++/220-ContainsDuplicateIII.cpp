/*
You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
{


    // Hold the map for the buckets
    unordered_map<int, int> buckets;

    // Hold the start of the sliding window
    int window_start = 0;

    // Loop through the vector
    for(int window_end = 0; window_end < nums.size(); window_end++)
    {

        // Hold the value at the end of the window
        int x = nums[window_end];

        // Hold the bucket id
        int id = static_cast<int>(x/(valueDiff+1));

        // Check if we have a negative value
        if(x < 0) 
        {
            --id;
        }

        // Check if the id is in buckets
        if(buckets.find(id) != buckets.end())
        {
            return true;
        }
        
        // Check if the bucket on the left has a valid diff
        else if(buckets.find(id-1) != buckets.end() && (long)abs(buckets[id-1] - x) <= valueDiff)
        {
            return true;
        }

        // Check if the bucket on the right has a valid diff
        else if(buckets.find(id+1) != buckets.end() && (long)abs(buckets[id+1] - x) <= valueDiff)
        {
            return true;
        }

        // Add the value to the buckets
        buckets[id] = x;

        // Check if we need to remove a bucket
        if(buckets.size() == indexDiff + 1)
        {
            // Get the value being removed
            x = nums[window_start];

            // Calculate the id
            id = static_cast<int>(x/(valueDiff+1));

            // Check if the value was negative
            if(x < 0)
            {
                id--;
            }

            // Erase the bucket
            buckets.erase(id);

            // Increment the sliding window
            window_start++;
        }
    }    

    return false;
}
