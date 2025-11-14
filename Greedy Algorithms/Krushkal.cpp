// This program create MST with help of Krushkal algorithm
// instead of the DSU we are just adding neignour of each vertex
// to each vertex.

#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int v,u,w;
};
vector<vector<int>> Parent;

// For making each vertex their own neighbour
void first_parent(int n) {
    Parent.resize(n);
    for (int i = 0; i < n; i++) {
        Parent[i].push_back(i);
    }
}

// For checking the cycle present or not
bool Cycle_check(int a, int b) {
    for (auto x : Parent[a]) {
        for (auto y : Parent[b]) {
            if (x == y) return false;
        }
    }
    return true;
}

//If cycle not present add it to mst
void merge(int v, int u) {
    for (auto x : Parent[u]) {
        if ( find(Parent[v].begin(),Parent[v].end(),x) == Parent[v].end()) {
            Parent[v].push_back(x);
        }
    }
    for (auto x : Parent[v]) {
        if ( find(Parent[u].begin(),Parent[u].end(),x) == Parent[u].end()) {
            Parent[u].push_back(x);
        }
    }
}

int main() {
    vector<Edge> edge ={
        {0,1,4},
        {1,2,5},
        {0,2,8},
        {2,3,2},
    };
    int Total_cost = 0;
    vector<Edge> MST; // MST array

    // Sort the vector of edges
    sort(edge.begin(),edge.end(),[](Edge a, Edge b){return a.w < b.w;});

    first_parent(4);

    for (auto &e : edge) {
        if (Cycle_check(e.v,e.u)) {
            Total_cost += e.w;
            merge(e.v,e.u);
            MST.push_back(e);
        }
    }

    for (auto x : MST) {
        cout<<x.v<<" - "<<x.u<<" :"<<x.w<<"\n";
    }

    cout<<"Tota Mst cost : "<<Total_cost<<"\n";
    return 0;
}