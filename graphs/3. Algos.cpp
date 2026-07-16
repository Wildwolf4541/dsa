/*
    - Reorder Routes- forward and backward edgeLists banengi.
    - Number of Provinces- for each unvisited node, run a bfs/dfs loop.
    - Number of operations to make networks connected- Find component counts, if givenedges>=n-1 ?count-1:-1
    
    - Cycle Detection- Undirected BFS -> visited, parent array, if nbr not parent -> cycle
    - Cycle Detection- Undirected DFS -> visited, parent int, if nbr not parent -> cycle
    - Cycle Detection- Directed -> visited, path Visited, same encountered -> cycle

    - Eventual Safe States- Cycle Detection Directed, Answer is (All Nodes - PathVisited).
    - Longest Cycle- Cycle Detection Directed, path Visited ki values. (Node-Nbr+1).
    - Is Graph Bipartite- Normal BFS/DFS with !visited. assign different colours to nbrs, if same colour found return false, else true.

*/

/* 
=================================================================
                    TOPOLOGICAL SORT
=================================================================
Nodes with no pre-requiste should be visited first.
    * sorting (Arranging nodes) in a specific order.
    * Directed Acyclic Graph (DAG).
    * Not for undirected graphs and cyclic graphs.

Two ways to implement-
    * BFS based- // Kahn's Algorithm //
    * DFS based- Nodes storing order changes. use of deque. backtracking mei push karenge node.

Kahn's Algorithm-> 
1. Calculate indegree of every node.
2. Push all nodes with indegree = 0 into queue. Pop node. Add to answer.
3. Decrease indegree of neighbours. If neighbour indegree becomes 0, push it.

Cycle Detection using Kahn: If topoSort size < number of nodes => Cycle exists.

    - Course Schedule I  - Cycle Detection Directed.
    - Course Schedule II - Topological Sort
    - Largest Colour Value in a Directed Graph - Topological Sort, colourcount array maintain and update max colour coming on that node. Return the Max Count.

*/

/*
=================================================================
                    GRID TRAVERSAL
=================================================================
har cell ko ek node consider karo aur neighours saath vaale cells. either 4 or 8.
dx=[0,-1,0,1], dy=[-1,0,1,0]
dx = {-1,-1,-1,0,0,1,1,1}, dy = {-1,0,1,-1,1,-1,0,1}

    - flood fill- Store original color. BFS/DFS only on cells having original color. Change color while visiting.
    - number of islands- Traverse entire grid. If cell == '1': Multi DFS/BFS -> Mark visited -> count++ in main.
    - Rotten Oranges- Multi BFS hoga. count on levels. push rotten oranges only.
    - 01 Matrix- push all 0s in queue, BFS on nodes to search for 1s and unvisited. increment them.
    - Geeks Village and Wells- almost same as 01 Matrix.
    - Number of enclaves- Borders se DFS start karo jahan pe 1 hai. Jahan dfs mei 1 mile mark it 0. end mei traverse the grid and count 1s left.
    - Surrounded Regions- Same as Number of enclaves.
*/

/*
=================================================================
                    Shortest Path
=================================================================
Two Type-> 
    * Single Source Shortest Path
        * Weighted -> +ve Djikstra, -ve Bellman-Ford
        * UnWeighted -> BFS

    * All Source Shortest Path
        -> -ve Floyd Warshall
    
Djikstra Algorithm-> 
1. Initialize distances
2. Push source in a queue, Pop minimum, Skip outdated
3, Traverse neighbors, Better options-> Update distance
4. Push neighbor
5. Repeat until empty and Return distances

    - Snakes and ladders- change the board using flag, build the graph for steps, use levelwise bfs.
    - Dijkstra Algorithm- Priority Queue (min-heap). Store {dist,node}. Relax edges, skip outdated entries (if currDist > dist[node]).
    - Path With Minimum Effort- Dijkstra. Store {effort,{x,y}}. New effort = max(currEffort, abs(heightDiff)). Minimize maximum effort.
    - Cheapest Flights Within K Stops- BFS (Queue). Store {stops,node,cost}. Relax only if cheaper and stops <= k.
    - Network Delay Time- Dijkstra. Store {time,node}. Find shortest time to every node, answer = maximum distance, if unreachable return -1.
    - Number of Ways to Arrive at Destination- Modified Dijkstra. Maintain dist[] and ways[]. Better path -> update both, equal path -> ways += ways[parent].
*/