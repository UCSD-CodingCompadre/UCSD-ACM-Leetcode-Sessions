function isBipartite(graph: number[][]): boolean 
{
    
    // Hold the size of the graph
    const n: number = graph.length;

    // Hold the visited nodes for set A
    const visitedA: Set<number> = new Set();

    // Hold the visited nodes for set B
    const visitedB: Set<number> = new Set();

    // Loop through each potential starting node
    for (let startNode = 0; startNode < n; ++startNode)
    {
        
        // Check if we already iterated through the node
        if (!visitedA.has(startNode) && !visitedB.has(startNode)) 
        {
            
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

function dfs(graph: number[][], index: number, visitedA: Set<number>, visitedB: Set<number>, isInSetA: boolean): boolean
{
    
    // Hold a reference to the current set
    const currentSet: Set<number> = isInSetA ? visitedA : visitedB;

    // Check if the current set has the node
    if (currentSet.has(index)) 
    {
        return true;
    }

    // Check if the node is supposed to go in set A
    if (isInSetA)
    {
        // Insert to set A
        visitedA.add(index);
    } else {
        // Insert to set B
        visitedB.add(index);
    }

    // For each neighbor of the node, apply the dfs function
    for (const neighbor of graph[index]) 
    {
        
        // Check if the neighbor is in the current set
        if (currentSet.has(neighbor) || !dfs(graph, neighbor, visitedA, visitedB, !isInSetA)) 
        {
            
            // Return false, causing the whole recursive stack to return false
            return false;
        }
    }

    // Return true once the neighbors have been checked
    return true;
}
