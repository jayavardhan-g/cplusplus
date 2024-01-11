#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<vector<int>> v(40);
int dp[1LL<<10][40];
int p;

int solve(int mask, int h){
    int done= __builtin_popcount(mask);
    if(done>=p)return 1;
    if(h>=40)return 0;

    if(dp[mask][h]!=-1)return dp[mask][h];

    int ans=0;
    for(int i=0;i<v[h].size();i++){
        if( !(mask&(1LL<<v[h][i])) ){
            ans+= solve( mask|1LL<<v[h][i] ,h+1 );
        }
    }
    ans+= solve(mask,h+1);

    return dp[mask][h] = ans;
}

int numberWays(vector<vector<int>> &h){
    for(int i=0;i<h.size();i++){
        for(int j=0;j<h[i].size();j++){
            v[h[i][j]-1].push_back(i);
        }
    }
    p=h.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,0);
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