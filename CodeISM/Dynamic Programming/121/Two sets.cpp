//https://cses.fi/problemset/task/1093
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int M= 1e9 + 7;
int dp[501][100001];

int invmod(int n,int m){
    if(m==0)return 1;

    if(m%2==1){
        return ((n%M)*(invmod((n%M*n%M)%M,m/2)%M))%M;
    }else{
        return (invmod((n%M*n%M)%M,m/2))%M;
    }
}

int rec(int sum,int i){
    if(sum<0)return 0;
    if(sum==0)return 1;
    if(i<0)return 0;
    if(dp[i][sum]!=-1)return dp[i][sum];

    int p = rec(sum-i,i-1);
    int np = rec(sum, i-1);

    return dp[i][sum]= (p + np)%M; 
}

int32_t main(){
    int n;cin>>n;
    int sum = n*(n+1);
    sum/=2;

    // cout<<invmod(2,1e9+5);
    memset(dp,-1,sizeof(dp));
    if(sum%2==0){
        cout<<(rec( sum/2, n)* invmod(2,1e9+5) )%M;
    }else{
        cout<<0;
    }
}