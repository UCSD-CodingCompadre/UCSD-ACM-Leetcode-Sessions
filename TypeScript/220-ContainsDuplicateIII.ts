/*
You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.
*/
function containsNearbyAlmostDuplicate(nums: number[], indexDiff: number, valueDiff: number): boolean {
    
    // Hold the map for the buckets
    let buckets: Map<number, number> = new Map<number, number>();

    // Hold the start of the sliding window
    let window_start: number = 0;

    // Loop through the vector
    for(let window_end: number = 0; window_end < nums.length; window_end++)
    {

        // Hold the value at the end of the window
        let x: number = nums[window_end];

        // Hold the bucket id
        let id: number = Math.floor(x/(valueDiff+1));

        // Check if the id is in buckets
        if(buckets.has(id))
        {
            return true;
        }
        
        // Check if the bucket on the left has a valid diff
        else if(buckets.has(id-1) && Math.abs(buckets[id-1] - x) <= valueDiff)
        {
            return true;
        }

        // Check if the bucket on the right has a valid diff
        else if(buckets.has(id+1) && Math.abs(buckets[id+1] - x) <= valueDiff)
        {
            return true;
        }

        // Add the value to the buckets
        buckets.set(id, x); 

        // Check if we need to remove a bucket
        if(buckets.size == indexDiff + 1)
        {
            // Get the value being removed
            x = nums[window_start];

            // Calculate the id
            id = Math.floor(x/(valueDiff+1));

            // Erase the bucket
            buckets.delete(id);

            // Increment the sliding window
            window_start++;
        }
    }    

    return false;
};