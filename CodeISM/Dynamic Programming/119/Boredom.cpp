//https://codeforces.com/problemset/problem/455/A%7C
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int L= 1e5+1;

int32_t main(){
    int n;cin>>n;
    int f[L];
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++){
        int x;cin>>x;
        f[x]+= x;
    }
    // int dp[L]={0};
    // dp[1]=f[1];
    // dp[2]=f[2];
    
    for(int i=3;i<=L;i++){
        f[i] += max(f[i-2],f[i-3]);
        // cout<<f[i]<<' '<<endl;
    }
    cout<<max(f[L-2],f[L-1]);
}
