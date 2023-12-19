//https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<vector<int>> v;
long long solve(long long mask){
    int n= __builtin_popcount(mask);

    if(n==v.size())return 1;

    int ans=0;
    for(int i=0;i<40;i++){
        if(!(mask&(1LL<<i))){
            for(int j=0;j<v[n].size();j++){
                if(i+1 == v[n][j]){
                    ans += solve(mask|(1LL<<i));
                }
            }
        }
    }
    return ans;
}

int numberWays(vector<vector<int>>& hats) {
    v=  hats;
    return solve(0);
}

int32_t main(){
    int n;cin>>n;
    vector<vector<int>> h(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        for(int j=0;j<x;j++){
            int z;cin>>z;
            h[i].push_back(z);
        }
    }
    cout<<numberWays(h);
}