//www.codingninjas.com/studio/problems/cost-to-cut-a-chocolate_3208460
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int s,int e,vector<int> &c,vector<vector<int>> &dp){
    if(s==e)return 0;
    if(dp[s][e]!=-1)return dp[s][e];

    int ans=INT_MAX;
    for(int i=0;i<c.size();i++){
        if(c[i]>=s && c[i]<e){
            ans=min(ans, e-s+1 + rec(s,c[i],c,dp) + rec(c[i]+1,e,c,dp));
        }
    }
    if(ans==INT_MAX)return dp[s][e]=0;
    else return dp[s][e]=ans;
}
int cost(int n, int c, vector<int> &cuts){
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return rec(1,n,cuts,dp);
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        vector<int> v(c);
        for(int i=0;i<c;i++)cin>>v[i];
        cout<<cost(n,c,v)<<endl;
    }
}