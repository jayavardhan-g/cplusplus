//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/jump-k-forward-250d464b/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int M= 1e9 + 7;

int32_t main(){
    int n,k;cin>>n>>k;
    int dp[n]={0};
    dp[0]=1;
    // for(int i=0;i<n;i++)cout<<dp[i];
    for(int i=0;i<n;i++){
        for(int j=1;j<=k && i+j<n ;j++){
            dp[i+j]= (dp[i]%M + dp[i+j]%M)%M;
        }
    }
    cout<<dp[n-1]<<endl;
}