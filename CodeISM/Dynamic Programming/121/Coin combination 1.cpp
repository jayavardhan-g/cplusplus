#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
const int M= 1e9 + 7 ;
// vector<int> v;
// int n;

int rec(int k,int v[],int n){
    if(k==0)return 1;
    if(dp[k]!=-1)return dp[k];
 
    int ways=0;
    for(int i=0;i<n;i++){
        if(v[i]<=k)ways = (ways%M + rec(k-v[i],v,n)%M)%M;
    }
 
    return dp[k]=ways;
}
 
int32_t main(){
    int n,sum;
    cin>>n>>sum;
    // v.resize(n);
    int v[n];
    for(int i=0;i<n;i++)cin>>v[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(sum,v,n)<<endl;
}
// #include<bits/stdc++.h>
// using namespace std;
// const int M=1e9+7;
// int dp[1000001];
// int n,k;
// vector<int> v;
// int rec(int sum){
//   if(sum==0)return 1;
//   if(dp[sum]!=-1)return dp[sum];
 
//   int ans=0;
//   for(int i=0;i<n;i++){
//     // cout<<i<<' '<<v[i]<<' '<<sum<<endl;
//     if(v[i]<=sum)ans= (ans%M+ rec(sum-v[i])%M)%M;
//   }
//   return dp[sum]=ans;
// }
 
// int32_t main(){
//   cin>>n>>k;
//   v.resize(n);for(int i=0;i<n;i++)cin>>v[i];
//   memset(dp,-1,sizeof(dp));
//   int ans=rec(k);
//   cout<<ans;
// }