// This is a simple knapsack problem using DP
#include<bits/stdc++.h>
using namespace std;

int f(int ind, int W, vector<int> &wt, vector<int> &val) {
    if (ind == 0) {
        if (wt[0] <= W) return val[0];
        return 0;
    }

    int notTake = 0 + f(ind-1, W, wt, val);
    int Take = 0;

    if (wt[ind] <= W) {
        Take = val[ind] + f(ind-1, W - wt[ind],wt,val);
    }

    return max(notTake,Take);
}

int main() {

    vector<int> wt = {10,5,22};
    vector<int> val = {50,30,75};
    int W = 25;
    int ind = 2;

    auto a = f(ind,W,wt,val);

    cout<<"Max val: "<<a;
    return 0;
}
