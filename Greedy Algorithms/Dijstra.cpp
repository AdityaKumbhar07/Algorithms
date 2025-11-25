// Simple Dijstra algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> Dijstra(int src, int n, vector<vector<pair<int,int>>> &adj){

    int INF = 1e9;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n,INF);

    dist[src] = 0;
    pq.emplace(0,src);

    while(!pq.empty()){
        auto p = pq.top();
        int d = p.first;
        int u = p.second;
        pq.pop();

        for(auto &p : adj[u]){
            int v = p.first;
            int w = p.second;

            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.emplace(dist[v],v);
            }
        }
    }
    return dist;
}

int main() {

    int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};

    
    vector<int> ans = Dijstra(0,5,adj);
    for (auto x : ans) {
        cout<<x<<" ";
    }
    return 0;
}