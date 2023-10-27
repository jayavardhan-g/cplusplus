// https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int dp[1000001];
int n,k;
vector<int> v;
int rec(int sum){
  if(sum==0)return 1;
  if(dp[sum]!=-1)return dp[sum];

  int ans=0;
  for(int i=0;i<n;i++){
    cout<<i<<' '<<v[i]<<' '<<sum<<endl;
    if(v[i]<=sum)ans= (ans%M+ rec(sum-v[i])%M)%M;
  }
  return dp[sum]=ans;
}

int32_t main(){
  cin>>n>>k;
  v.resize(n);for(int i=0;i<n;i++)cin>>v[i];
  memset(dp,-1,sizeof(dp));
  int ans=rec(k);
  cout<<ans;
}
// #include <bits/stdc++.h>
 
// using namespace std;
 
// const int MAX = 1e6;
// const int MOD = 1e9 + 7;
 
// int n;
// int x;
// vector<int> coins;
// int dp[MAX + 1];
 
// int solve(int sum) {
//   if (sum == 0) return 1;
//   if (dp[sum] != -1) return dp[sum];
 
//   int ans = 0;
//   for (int i = 0; i < n; i++) {
//     // cout<<i<<' '<<coins[i]<<' '<<sum<<endl;
//     if (coins[i] <= sum) {
//       ans = (ans + solve(sum - coins[i])) % MOD;
//     }
//   }
 
//   return dp[sum] = ans;
// }
 
// int32_t main() {
//   cin >> n >> x;
 
//   coins.resize(n);
 
//   for (int i = 0; i < n; i++) cin >> coins[i];
 
//   for (int i = 0; i <= MAX; i++) {
//     dp[i] = -1;
//   }
 
//   cout << solve(x);
 
//   return 0;
// }