#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

// Undirected Graph Cycle Detection using DFS
    bool dfs(int node, vector<int> adj[], vector<int> &visited, int parent) {
        visited[node] = 1;

        for (int nbr : adj[node]) {
            // If neighbour is not visited
            if (!visited[nbr]) {
                if (dfs(nbr, adj, visited, node))
                    return true;
            }
            // If neighbour is visited and is not the parent
            else if (nbr != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, -1))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    Solution obj;

    if (obj.isCycle(V, adj))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}

// undirected graph cycle detection using BFS
/*
    bool bfs(int node, vector<int>adj[], vector<int>&visited, vector<int>&parent){
        visited[node] = 1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                int neighbour=adj[node][i];
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    parent[neighbour]=node;
                    q.push(neighbour);
                }
                else{
                    if(parent[node]!=neighbour){
                        return true;
                    }
                }
            }
        }
        return false;
    } 
    bool isCycle(int V, vector<int>adj[]){
        vector<int>visited(V,0);
        vector<int>parent(V,-1);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited,parent))
                    return true;
            }
        }
        return false;
    }
*/

// Directed Graph Cycle Detection using DFS
/*
    bool dfs(int node, vector<int>adj[], vector<int>&visited, vector<int>&pathVisited){
        visited[node]=1;
        pathVisited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            int nbr=adj[node][i];
            if(!visited[nbr]){
                bool res= dfs(nbr,adj,visited,pathVisited);
                if(res==true){
                    return true;
                }
            }
            else{
                if(pathVisited[nbr]==1){
                    return true;
                }
            }
            pathVisited[node]=0;
        }
        return false;
    }
    bool isCycle(int V, vector<int>adj[]){
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if (dfs(i,adj,visited,pathVisited)){
                    return true;
                }
            }
        }
        return false;
    }
*/