//https://codeforces.com/problemset/problem/189/A
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int L= 4001;

int32_t main(){
    int n,a,b,c;cin>>n>>a>>b>>c;
    int dp[L];
    memset(dp,0,sizeof(dp));
    // for(int i=1;i<=n;i++){
    //     int x= 0;
    //     if(i-a>=0)x= max(x,dp[i-a]);
    //     if(i-b>=0)x= max(x,dp[i-b]);
    //     if(i-c>=0)x= max(x,dp[i-c]);


    // }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i-a>=0){
            if(i-a==0)dp[i]=max(dp[i],1LL);
            if(i-a>0 && dp[i-a]>0) dp[i] = max(dp[i], 1+dp[i-a]);
        }
        if(i-b>=0){
            if(i-b==0)dp[i]=max(dp[i],1LL);
            if(i-b>0 && dp[i-b]>0) dp[i] = max(dp[i], 1+dp[i-b]);
        }
        if(i-c>=0){
            if(i-c==0)dp[i]=max(dp[i],1LL);
            if(i-c>0 && dp[i-c]>0) dp[i] = max(dp[i], 1+dp[i-c]);
        }
        // cout<<dp[i]<<' ';
    }
    // cout<<endl;
    cout<<dp[n]<<endl;  
}