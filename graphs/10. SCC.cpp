#include<bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (auto nbr : adj[node]) {
        if (!vis[nbr])
            dfs1(nbr, adj, vis, st);
    }

    st.push(node);
}

void dfs2(int node, vector<int> revAdj[], vector<int>& vis) {
    vis[node] = 1;

    for (auto nbr : revAdj[node]) {
        if (!vis[nbr])
            dfs2(nbr, revAdj, vis);
    }
}

int kosaraju(int V, vector<int> adj[]) {

    stack<int> st;
    vector<int> vis(V, 0);

    // Step 1: Store nodes according to finishing time
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            dfs1(i, adj, vis, st);
    }

    // Step 2: Reverse the graph
    vector<int> revAdj[V];

    for (int i = 0; i < V; i++) {
        vis[i] = 0;

        for (auto nbr : adj[i]) {
            revAdj[nbr].push_back(i);
        }
    }

    // Step 3: DFS in stack order
    int scc = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            scc++;
            dfs2(node, revAdj, vis);
        }
    }

    return scc;
}