//https://atcoder.jp/contests/dp/tasks/dp_n
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int dp[401][401];

int rec(int lo,int hi,int v[]){
    if(dp[lo][hi]!=-1)return dp[lo][hi];
    if(lo>=hi)return 0;
    // if(lo==hi)return v[lo];

    int sum=0;
    for(int i=lo;i<=hi;i++){
        sum+= v[i];
    }
    int ans=LONG_LONG_MAX;
    for(int i=lo+1;i<=hi;i++){
        // z+=v[i-1];
        ans = min(ans, sum+ rec(lo,i-1,v) + rec(i,hi,v) );
    }
    return dp[lo][hi]=ans;
}

int32_t main(){
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    cout<<rec(0,n-1,a);
}