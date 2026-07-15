#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    int n = adj.size();
    vector<int> distances(n, INT_MAX);

    distances[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        // Taking front out
        auto pr = pq.top();
        pq.pop();

        int dist_of_node_from_src = pr.first;
        int node = pr.second;

        // Iterate over neighbors
        for (auto &nbr_info : adj[node]) {
            int nbr = nbr_info.first;
            int weight = nbr_info.second;

            int saved_dist_of_nbr_from_src = distances[nbr];
            int new_dist_of_nbr_from_src = dist_of_node_from_src + weight;

            // Check if reaching nbr with lesser distance via current node
            if (new_dist_of_nbr_from_src < saved_dist_of_nbr_from_src) {
                pq.push({new_dist_of_nbr_from_src, nbr});
                distances[nbr] = new_dist_of_nbr_from_src;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (distances[i] == INT_MAX) {
            distances[i] = -1;
        }
    }

    return distances;
}