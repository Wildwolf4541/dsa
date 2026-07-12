#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSortBFS(vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> indegree(n,0);
    vector<int> ans;

    // getting every node's indegree.
    for(int i=0;i<n;i++){
        for(auto &j:adj[i]){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(int i=0;i<adj[node].size();i++){
            int nbr=adj[node][i];
            indegree[nbr]--;
            if(indegree[nbr]==0)
                q.push(nbr);
        }
    }
    return ans;
}

// Topological Sort using DFS
deque<int>dq;
void DFS(int node, vector<vector<int>>& adj, vector<int>&visited){
    visited[node]=1;
    for(int &nbr:adj[node]){
        if(!visited[nbr]){
            DFS(nbr,adj,visited);
        }
    }
    dq.push_front(node);
}
vector<int>topologicalSortDFS(vector<vector<int>>& adj){ // int main
    int n=adj.size();
    vector<int>visited(n);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i,adj,visited);
        }
    }
    vector<int>ans;
    for(int i=0;i<dq.size();i++){
        ans.push_back(dq[i]);
    }
    return ans;
}