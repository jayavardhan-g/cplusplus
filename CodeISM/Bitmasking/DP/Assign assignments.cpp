#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int n;
int mat[20][20];
int d[1LL<<20];
// int dp[1];

int solve(int mask){
    if(d[mask]!=-1)return d[mask];

    int s= __builtin_popcount(mask);
    if(s>=n)return 1;
    int ans=0;
    for(int i=0;i<n;i++){
        if( !(mask&1<<i) && mat[s][i] ){
            ans+= solve(mask|1<<i);
        }
    }
    return d[mask]= ans;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>mat[i][j];
        }
        memset(d,-1,sizeof(d));
        // memset(dp,-1,sizeof(dp));
        cout<<solve(0)<<endl;
    }
}