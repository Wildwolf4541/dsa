/*
    - Reorder Routes- forward and backward edgeLists banengi.
    - Rotten Oranges- Multi BFS hoga.
    
    - Cycle Detection- Undirected BFS -> visited, parent array, if nbr not parent -> cycle
    - Cycle Detection- Undirected DFS -> visited, parent int, if nbr not parent -> cycle
    - Cycle Detection- Directed -> visited, path Visited, same encountered -> cycle

    - Eventual Safe States- Cycle Detection Directed, Answer is (All Nodes - PathVisited).
    - Longest Cycle- Cycle Detection Directed, path Visited ki values. (Node-Nbr+1).
*/

/* 
Topological Sort -> Nodes with no pre-requiste should be visited first.
    * sorting (Arranging nodes) in a specific order.
    * Directed Acyclic Graph (DAG).
    * Not for undirected graphs and cyclic graphs.

Two ways to implement-
    * BFS based- // Kahn's Algorithm //
    * DFS based- Nodes storing order changes. use of deque. backtracking mei push karenge node.

Kahn's Algorithm-> push nodes in a queue whose indegree is 0. 
                   push nbrs of those nodes when indegree becomes zero.


    - Course Schedule I  - Cycle Detection Directed.
    - Course Schedule II - Topological Sort
    - Largest Colour Value in a Directed Graph - Topological Sort, colourcount array maintain and update max
                                                 colour coming on that node. Return the Max Count.

*/