#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int M=1e9+7;

int rec(int i,int dp[]){
    if(i==0)return 1;
    if(i==1)return 1;
    if(dp[i]!=-1)return dp[i];

    return dp[i]= (rec(i-1,dp)%M + rec(i-2,dp)%M)%M;
}

int32_t main(){
    int n,m;cin>>n>>m;
    int dp[n+1];
    // memset(dp,-1,sizeof(dp));
    // for(int i=0;i<m;i++){
    //     int x;cin>>x;
    //     dp[x]=0;
    // }

    // cout<<rec(n,dp);
    // return 0;
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    
    for(int i=0;i<m;i++){
        int x;cin>>x;
        dp[x]=0;
    }

    // for(int i=0;i<n;i++){
    //     cout<<i<<dp[i]<<endl;
    // }
    for(int i=2;i<n+1;i++){
        if(dp[i]==-1){
            dp[i]=( dp[i-1]%M + dp[i-2]%M )%M;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<i<<dp[i]<<endl;
    // }
    
    cout<<dp[n]<<endl;
    // int x= 3344930216562163528%M;
    // cout<<x;
}