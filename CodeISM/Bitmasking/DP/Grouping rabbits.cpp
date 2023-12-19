//https://atcoder.jp/contests/dp/tasks/dp_u
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int a[16][16];
int dp[1LL<<16];

int solve(int mask){
    if(dp[mask]!=-1)return dp[mask];
    if(mask==0)return 0;
    // int ans=0;
    vector<int> v;

    for(int i=0;i<16;i++){
        if(mask & (1LL<<i))v.push_back(i);
    }
    int temp=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            temp+= a[v[i]][v[j]];
        }
    }
    int ans= temp; 
    for(int i=(mask-1)&mask;i>0;i= (i-1)&mask){
        ans=max(ans, solve(i) + solve(i^mask));
        // ans=max(ans, solve(mask^((1LL<<i)-1)));
    }

    return dp[mask]= ans;
}

int32_t main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    int x = (1LL<<n)-1;
    memset(dp,-1,sizeof(dp));
    cout<<solve(x);
}

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int INF;
// int a[16][16];
// int dp[1<<16]; // initalize with -INF or -1e18
// int n;

// int solve (int mask)
// {
//   if ( dp[mask]!= -1) 
//   {
//        return dp[mask];
//    }
//   // Case 1: All the set bits are in same group
//     int ans=0;  
//     for(int i=0; i<n; i++)
//     {
//      for(int j=i+1; j<n; j++)
//       {
//          if ( (mask & (1<<i)) && (mask & (1<<j)) )ans += a[i][j];
//        }
//     }
//     // Case 2: iterate through all submasks of given mask
//     for( int i = mask&(mask-1); i>0; i=(i-1) & mask)
//     {
//         ans= max(ans, solve(i)+solve(i^mask));
//     // ans  = max(ans, solve(i) + solve( mask ^ i ) );
//     }
//     return dp[mask]=ans;
// }

// int32_t main(){
//   cin>>n;
//   for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
// //   for(int  i=0;i<(1<<16);i++)dp[i]=-INF;
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<n;j++)cout<<a[i][j]<<' ';
//     //     cout<<endl;
//     // }
//     memset(dp,-1,sizeof(dp));
//   cout<<solve((1<<n)-1);
// }