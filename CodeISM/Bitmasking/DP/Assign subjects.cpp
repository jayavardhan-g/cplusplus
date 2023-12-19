//https://www.spoj.com/problems/ASSIGN/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int dp[1LL<<20][20];
int n;
int mat[20][20];
int d[1LL<<20];
int solve(int mask,int s){
    if(s>=n)return 1;
    if(dp[mask][s]!=-1)return dp[mask][s];
    int ans=0;

    for(int i=0;i<n;i++){
        if(mat[s][i]==1 && !(mask &(1LL<<i) ) ){
            ans += solve(mask|(1LL<<i),s+1);
        }
    }
    return dp[mask][s]=ans;
}
int solve(int mask){
    int s= __builtin_popcount(mask);
    if(s>=n)return 1;
    if(d[mask]!=-1)return d[mask];
    int ans=0;

    for(int i=0;i<n;i++){
        if(mat[s][i]==1 && !(mask &(1LL<<i) ) ){
            ans += solve(mask|(1LL<<i));
        }
    }
    return d[mask]=ans;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>mat[i][j];
        }
        memset(d,-1,sizeof(d));
        memset(dp,-1,sizeof(dp));
        cout<<solve(0)<<endl;
    }
}