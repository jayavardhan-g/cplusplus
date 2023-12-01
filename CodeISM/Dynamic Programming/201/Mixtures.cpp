#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int v[100];
int dp[100][100];

int  rec(int lo,int hi){
    if(dp[lo][hi]!=-1)return dp[lo][hi];
    if(lo>=hi)return 0;

    int  sum=0;
    for(int i=lo;i<=hi;i++)sum+=v[i];
    int z=0;
    int ans=LONG_LONG_MAX;
    for(int i=lo+1;i<=hi;i++){
        z+= v[i-1];
        ans = min(ans, (z%100)*((sum-z)%100) + rec(lo,i-1) + rec(i,hi));
    }
    return dp[lo][hi] = ans;
}

int32_t main(){
    int n;
    while(cin>>n){    
        for(int i=0;i<n;i++)cin>>v[i];
        memset(dp,-1,sizeof(dp));
        cout<<rec(0,n-1)<<endl;
    }
}