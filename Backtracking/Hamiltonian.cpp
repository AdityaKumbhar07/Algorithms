#include<iostream>
using namespace std;

int Total_vert = 8;
int g[8][8] = {
    //0 1 2 3 4 5 6 7
    {0,1,1,0,1,1,0,0}, //0
    {1,0,1,0,1,1,0,0}, //1
    {1,1,0,1,0,0,1,0}, //2
    {0,0,1,0,0,0,0,1}, //3
    {1,1,0,0,0,1,0,0}, //4
    {1,1,0,0,1,0,1,0}, //5
    {0,0,1,0,0,1,0,1}, //6
    {0,0,0,1,0,0,1,0}, //7
};

int path[8];
int visit[8];

bool hamil(int vert) {
    // Last vert is connected to first or not
    if (vert == Total_vert) return g[path[vert - 1]]  [path[0]];

    // Check every adjacent node
    for (int i = 0; i < Total_vert; i++) {
        // check if it is not repeated and connected to previous vert
        if (!visit[i] && g[path[vert - 1]][i]) {
            path[vert] = i;
            visit[i] = 1;
            if (hamil(vert + 1)) return true;
            visit[i] = 0; // Backtrack
        }
    }
    return false;
}
int main() {
    visit[0] = 1; // Starting vertex 0 as visited
    path[0] = 0; // First vertex to path
    if (hamil(1)){
        for (auto x : path) {
            cout<<x<<"->";}
        cout<<path[0];}
    else cout<<"No Hamiltonian cycle";

    return 0;
}