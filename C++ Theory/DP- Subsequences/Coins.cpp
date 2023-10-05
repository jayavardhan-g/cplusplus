//https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int sum,vector<int> &v,vector<vector<int>> &dp){
    if(sum==0)return 1;
    if(i==0){
        if(sum%v[i]==0)return 1;
        else return 0;
    }
    if(sum<0)return 0;
    if(dp[i][sum]!=-1)return dp[i][sum];
    
    int p=rec(i,sum-v[i],v,dp);
    int np=rec(i-1,sum,v,dp);
    return dp[i][sum]=p+np;
}

long count(vector<int> denominations, int n, int value)
{
    //rec
    vector<vector<int>> dp(n,vector<int>(value+1,-1));
    return rec(n-1,value,denominations,dp);
}

void base(){
    int n;cin>>n;
    vector<int> v(n);
    for(int  i=0;i<n;i++)cin>>v[i];
    int t;cin>>t;
    cout<<count(v,n,t);
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        base();
    }
}
