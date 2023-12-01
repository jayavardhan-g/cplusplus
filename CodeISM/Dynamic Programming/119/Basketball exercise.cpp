//https://codeforces.com/problemset/problem/1195/C
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
// int dp[100000][3];


// int rec(int i,int p,int h1[],int h2[]){
//     if(i<0)return 0;
//     if(dp[i][p]!=-1)return dp[i][p];

//     int nt= rec(i-1,p,h1,h2);
//     int t=0;
//     if(p!=1)t= max( h1[i] + rec(i-1,1,h1,h2), t );
//     if(p!=2)t= max( h2[i] + rec(i-1,2,h1,h2), t );

//     return dp[i][p]= max(t,nt);
// }

int32_t main(){
    int n;cin>>n;
    int h1[n],h2[n];
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>h1[i];
    for(int i=0;i<n;i++)cin>>h2[i];
    // cout<<rec(n-1,0,h1,h2);

    int dp[n][2];
    dp[0][0]=h1[0];
    dp[0][1]=h2[0];

    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0], h1[i] + dp[i-1][1] );
        dp[i][1] = max(dp[i-1][1], h2[i] + dp[i-1][0] );
    }

    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
}