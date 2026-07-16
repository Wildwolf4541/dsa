#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();

    // Take every node as an intermediate node
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Skip if path doesn't exist
                if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                    continue;

                dist[i][j] = min(dist[i][j],
                                 dist[i][via] + dist[via][j]);
            }
        }
    }

    // Negative Weight Cycle Detection
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            // Negative Weight Cycle Exists
            return;
        }
    }
}