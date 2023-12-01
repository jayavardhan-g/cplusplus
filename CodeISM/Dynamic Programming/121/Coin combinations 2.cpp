//https://cses.fi/problemset/task/1636
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int M= 1e9+7;

int32_t main(){
    int n,k;cin>>n>>k;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    // for(int i=0;i<k+1;i++)cout<<dp[i]<<' ';
    // for(int i=0;i<n;i++)cout<<dp[i]<<' ';
    // cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=k;j++){
            dp[j] = (dp[j-a[i]] + dp[j])%M;
        }
    }
    cout<<dp[k]<<endl;
}