// Simple burteforce algorithm of tsp with path
#include <bits/stdc++.h>
using namespace std;

int n = 4;
vector<vector<int>> g = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

vector<int> vis(4,0), BP, CP;
int BC = 1e9;

void tsp(int pos, int cost, int count){
	if (count == n){
		cost += g[pos][0];
		if(cost < BC){
			BC = cost;
			BP = CP;
		}
	return;
	}
	
	for(int i = 0; i < n;i++){
		if(!vis[i]){
			vis[i] = 1;
			CP.push_back(i);
			tsp(i, cost + g[pos][i],count+1);
			CP.pop_back();
			vis[i] = 0;		
		}
	}
}

int main() {
    vis[0] = 1;
    
    tsp(0,0,1);
    
    for(auto x : BP){
    	cout<<x<<"->";
	}
	cout<<"0\n";
	cout<<"Total minimum cost"<<BC;
    
    return 0;
}









