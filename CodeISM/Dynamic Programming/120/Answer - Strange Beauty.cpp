//https://codeforces.com/contest/1475/problem/G
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long
const int L=2e5+1;
int dp[L];
int f[L];

void solve(){
    int n;cin>>n;
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    int maxx=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        f[x]++;
        maxx= max(maxx,x);
    }
    int ans=0;
    for(int i=2;i<=maxx;i++){
        if(f[i]!=0){
            dp[i]=f[i];
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    // cout<<i<<' '<<f[i]<<"factors"<<j<<endl;
                    dp[i]=max(dp[i], dp[i/j] + f[i] );
                    dp[i]=max(dp[i], dp[j] + f[i] );
                }
            }
            // cout<<i<<' '<<dp[i]<<endl;
            ans= max(ans, dp[i]);
        }
    }
    // for(int i=0;i<=maxx;i++)cout<<i<<' '<<dp[i]<<endl;
    ans+= f[1];
    cout<<n-ans<<endl;
}

int32_t main(){
    int t;cin>>t;
    while(t--)solve();
}