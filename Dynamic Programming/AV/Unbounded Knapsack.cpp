#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int W,vector<int>&v,vector<int>&w,vector<vector<int>> &dp){
    if(W<0)return INT_MIN;
    if(W==0)return 0;
    if(i==-1)return 0;
    if(dp[i][W]!=-1)return dp[i][W];
    // if(i==0)return dp[i][W]=W>=w[0]?v[0]:0;

    int p1,p2,np;
    p1=v[i]+rec(i,W-w[i],v,w,dp);
    p2=v[i]+rec(i-1,W-w[i],v,w,dp);
    np=rec(i-1,W,v,w,dp);

    return dp[i][W]=max(p1,max(p2,np));
}

int32_t main(){
    int n,W;cin>>n>>W;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    vector<int> w(n);for(int i=0;i<n;i++)cin>>w[i];
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    cout<<rec(n-1,W,v,w,dp);
}