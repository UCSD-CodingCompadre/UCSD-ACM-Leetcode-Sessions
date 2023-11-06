/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <utility> 
#include <functional>

using namespace std;

// Create a tuple comparator 
    struct TupleComparator {
        
        bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
            
            // Return if true if the first element in the tuple is greate than the first element in the other tuple
            return get<0>(a) > get<0>(b); 
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        // Hold the solution
        vector<vector<int>> solution;

        // Hold a set of visited pairs
        set<pair<int,int>> visitedPairs;

        // Hold a priority queue for the tuples
        priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, TupleComparator> min_heap;

        // Add the first tuple 
        min_heap.push(make_tuple<int, int, int>(nums1[0] + nums2[0], 0, 0));

        // Add the first pair
        visitedPairs.insert(pair<int,int>(0,0));

        // Loop until the heap is empty or solution size reaches k
        while(!min_heap.empty() && solution.size() != k)
        {

            // Grab the tuple from the min heap
            tuple<int, int, int> currentTuple = min_heap.top();
            
            // Hold the sum
            int sum = get<0>(currentTuple);
            
            // Hold the index from nums1
            int num1Index = get<1>(currentTuple);
            
            // Hold the index from nums2
            int num2Index = get<2>(currentTuple);
            
            // Pop the element from the min heap
            min_heap.pop();

            // Push the new vector pair
            solution.push_back({nums1[num1Index], nums2[num2Index]});

            // Check the next possible pairs of index by incrementing nums1Index and see if that pair is visited
            if(num1Index + 1 < nums1.size() && visitedPairs.find(pair<int, int>(num1Index + 1, num2Index)) == visitedPairs.end())
            {

                // Add the tuple to the heap
                min_heap.push(tuple<int, int, int>(nums1[num1Index + 1] + nums2[num2Index], num1Index + 1, num2Index));
                
                // Add the pairs to the set
                visitedPairs.insert(pair<int, int>(num1Index + 1, num2Index));
            }

            // Check the next possible pairs of index by incrementing nums2Index and see if that pair is visited
            if(num2Index + 1 < nums2.size() && visitedPairs.find(pair<int, int>(num1Index, num2Index + 1)) == visitedPairs.end())
            {
                
                // Add the tuple to the heap
                min_heap.push(tuple<int, int, int>(nums1[num1Index] + nums2[num2Index + 1], num1Index, num2Index + 1));
                
                // Add the pairs to the set
                visitedPairs.insert(pair<int, int>(num1Index, num2Index + 1));
            }
        }

        // Return the solution
        return solution;
    }