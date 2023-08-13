#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    int rec(int i,int W, vector<int> &w,vector<int> &v,vector<vector<int>> &dp){
        if(W<0)return -1e9;
        if(W==0)return dp[i][W]=0;
        
        if(dp[i][W]!=-1)return dp[i][W];
        if(i==0)return dp[i][W]=W>=w[0]?v[0]:0;

        int p,np;
        p=v[i]+rec(i-1,W-w[i],w,v,dp);
        np=rec(i-1,W,w,v,dp);

        return dp[i][W]=max(p,np);
    }

int32_t main(){
    int n;cin>>n;int W;cin>>W;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    vector<int> w(n);for(int i=0;i<n;i++)cin>>w[i];

    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    cout<<rec(n-1,W,w,v,dp);

}