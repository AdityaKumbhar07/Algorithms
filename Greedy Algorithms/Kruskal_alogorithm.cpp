#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, u, w;
};

vector<int> parent;

int findParent(int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

bool unionSets(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    int vert = 9;
    vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){ return a.w < b.w; });

    parent.resize(vert);
    for (int i = 0; i < vert; i++) parent[i] = i;

    int totalCost = 0;
    for (auto &e : edges) {
        if (unionSets(e.v, e.u)) {
            totalCost += e.w;
            cout << e.v << " - " << e.u << " (" << e.w << ")\n";
        }
    }

    cout << "MST Weight = " << totalCost << "\n";
    return 0;
}