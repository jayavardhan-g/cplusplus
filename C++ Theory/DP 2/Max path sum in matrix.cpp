//www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int mem(int i,int j,vector<vector<int>> &v,vector<vector<int>> &dp){
    if(j>=v[0].size() || j<0)return INT_MIN;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==0)return dp[i][j]=v[i][j];

    int fs=mem(i-1,j,v,dp);
    int ss=mem(i-1,j-1,v,dp);
    int ts=mem(i-1,j+1,v,dp);

    dp[i][j]=v[i][j]+max(fs,max(ss,ts));
}

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];

    cout<<mem(i,j,v,dp);
}