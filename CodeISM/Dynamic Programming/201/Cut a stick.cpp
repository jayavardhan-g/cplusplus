// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int dp[100][100];

int rec(int lo,int hi,vector<int> &v,int i,int j){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==j)return hi-lo;

    int ans=1e9;
    for(int k=i;k<=j;k++){
        ans= min(ans, hi-lo + rec(lo,v[k],v,i,k-1) + rec(v[k],hi,v,k+1,j));
    }
    return dp[i][j]= ans;
}

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(),cuts.end());
    // cout<<rec(0,n,cuts,0,cuts.size()-1);
    memset(dp,-1,sizeof(dp));
    return rec(0,n,cuts,0,cuts.size()-1);
}

int32_t main(){
    int l;cin>>l;
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    cout<<minCost(l,v);    
}