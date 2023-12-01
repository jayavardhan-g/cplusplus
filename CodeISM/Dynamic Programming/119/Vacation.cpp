//https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    int dp[n][3];
    int v[n][3];
    for(int i=0;i<n;i++)cin>>v[i][0]>>v[i][1]>>v[i][2];

    dp[0][0]=v[0][0];
    dp[0][2]=v[0][2];
    dp[0][1]=v[0][1];

    for(int i=1;i<n;i++){
        dp[i][0] = v[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = v[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = v[i][2] + max(dp[i-1][1],dp[i-1][0]);
    }

    int ans = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    cout<<ans;
}