#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int M=1000000007;

int mem(vector<bool> &v,int i,vector<int> &dp){
    if(dp[i]!=-1)return dp[i];
    if(!v[i]){
        return dp[i]=0;
    }
    if(i==0)return 1;
    if(i==1)return dp[i]=mem(v,i-1,dp);

    int fs=mem(v,i-1,dp);
    int ss=mem(v,i-2,dp);
    int x=(fs%M + ss%M)%M;

    return dp[i]=x;
}

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<bool> v(n+1,1);
    vector<int> dp(n+1,-1);
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v[x]=0;
    }
    cout<<mem(v,n,dp);
}