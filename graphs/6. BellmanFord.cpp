#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>>&edges, int src){
    vector<int>dist(n,INT_MAX);
    dist[src]=0;

    for(int i=0;i<n-1;i++){
        for(vector<int>&edge:edges){
            int node=edge[0];
            int nbr=edge[1];
            int wt=edge[2];

            if(dist[node]==INT_MAX) continue;

            int newdistofnbr= dist[node]+wt;
            if(newdistofnbr<dist[nbr]){
                dist[nbr]=newdistofnbr;
            }
        }
    }
    // check for -ve weight cycle.
    for(vector<int>&edge:edges){
        int node=edge[0];
        int nbr=edge[1];
        int wt=edge[2];

        if(dist[node]==INT_MAX) continue;
        
        int newdistofnbr= dist[node]+wt;
        if(newdistofnbr<dist[nbr]){
            return {-1};
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX) dist[i]=1e8;
    }
    return dist;
}
