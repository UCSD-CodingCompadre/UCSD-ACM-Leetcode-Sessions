#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) 
{

    // Hold the size of the graph
    int n = graph.size();

    // Hold the visited nodes for set A
    unordered_set<int> visitedA;

    // Hold the visited nodes for set B
    unordered_set<int> visitedB;

    // Loop through each potential starting nodes
    for (int startNode = 0; startNode < n; ++startNode) 
    {

        // Check if we already iterated through the node
        if (visitedA.find(startNode) == visitedA.end() && visitedB.find(startNode) == visitedB.end()) {
            
            // Check if the dfs recursion function finds that the graph is bipartite
            if (!dfs(graph, startNode, visitedA, visitedB, true)) 
            {

                // Return false
                return false;
            }
        }
    }

    // Return that the graph is bipartite
    return true;
}

bool dfs(vector<vector<int>>& graph, int index, unordered_set<int>& visitedA, unordered_set<int>& visitedB, bool isInSetA) 
{

    // Hold a reference the current set
    unordered_set<int>& currentSet = (isInSetA) ? visitedA : visitedB;

    // Check if the current set has the node
    if (currentSet.find(index) != currentSet.end()) 
    {
        return true;
    }

    // Check if the node is suppose to go in set A
    if (isInSetA) 
    {

        // Insert to set A
        visitedA.insert(index);
    } 
    // Else is it suppose to go in set B
    else 
    {
        
        // Insert to set B
        visitedB.insert(index);
    }

    // For eaching neighbor of the node apply the dfs function
    for (int neighbor : graph[index]) 
    {

        // Check if the neighbor is in the current set 
        if (currentSet.find(neighbor) != currentSet.end() || !dfs(graph, neighbor, visitedA, visitedB, !isInSetA)) {
            
            // Return false causing the whole recursive stack to return false
            return false;
        }
    }

    // Return true once the neighbors have been checked
    return true;
}