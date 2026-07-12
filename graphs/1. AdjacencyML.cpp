#include<bits/stdc++.h>
using namespace std;

// Printing Graphs
void print_graph(vector<vector<int>>adjacencyMatrix){
    int n=adjacencyMatrix.size();
    for(int i=1;i<n;i++){
        cout<<"Node "<<i<<": Neighbours -> ";
        for(int j=1;j<n;j++){
            if(adjacencyMatrix[i][j]==1){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
void print_list(unordered_map<int,vector<int>>adjacencyList){
    for(auto i:adjacencyList){
        cout<<"Node "<<i.first<<": Neighbours -> ";
        for(int j=0;j<i.second.size();j++){
            cout<<i.second[j]<<" ";
        }
        cout<<endl;
    }
}

// BFS Traversal
void BFS(int source, unordered_map<int,vector<int>>adjacencyList, int n){
    vector<int>visited(n+1,0);
    queue<int>q;
    q.push(source);
    visited[source]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0;i<adjacencyList[node].size();i++){
            int neighbor=adjacencyList[node][i];
            if(!visited[neighbor]){
                visited[neighbor]=1;
                q.push(neighbor);
            }
        }
    }
}

//with adjacency matrix
        // for(int i=0;i<n;i++){
        //     if(AdjacencyMatrix[node][i]==1 && !visited[i]){
        //         visited[i]=1;
        //         q.push(i);
        //     }
        // }

// DFS traversal
void DFS(int source, unordered_map<int,vector<int>>adjacencyList, vector<int>&visited){
    visited[source]=1;
    cout<<source<<" ";
    for(int i=0;i<adjacencyList[source].size();i++){
        int neighbor=adjacencyList[source][i];
        if(!visited[neighbor]){
            DFS(neighbor, adjacencyList, visited);
        }
    }
}
// void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
//         visited[node] = 1;
//         for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
//             if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
//                 dfs(neighbor, isConnected, visited);
//             }
//         }
//     }

int main(){
    vector<vector<int>> edgeList = {{1, 2}, {1, 3}, {1, 4}, {4, 5}, {2, 5}, {3, 6}, {5, 6}, {5, 7}};
    int n=7;
    // Adjacency matrix
    vector<vector<int>>adjacencyMatrix(n+1,vector<int>(n+1,0));
    for(int i=0;i<edgeList.size();i++){
        int u=edgeList[i][0];
        int v=edgeList[i][1];
        adjacencyMatrix[u][v]=1;
        adjacencyMatrix[v][u]=1;
    }
    
    // Adjacency list
    unordered_map<int,vector<int>>adjacencyList;
    for(int i=0;i<edgeList.size();i++){
        int u=edgeList[i][0];
        int v=edgeList[i][1];
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    cout<<"Adjacency Matrix Representation of the Graph:"<<endl;
    print_graph(adjacencyMatrix);
    cout<<"Adjacency List Representation of the Graph:"<<endl;
    print_list(adjacencyList);
    cout<<"BFS Traversal of the Graph starting from Node 1:"<<endl;
    BFS(1, adjacencyList, n);
    cout<<endl;
    cout<<"DFS Traversal of the Graph starting from Node 1:"<<endl;
    vector<int>visited(n+1,0);
    DFS(1, adjacencyList, visited);
}