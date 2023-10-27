//https://cses.fi/problemset/task/1746/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int m;
int M=1e9+7;
int rec(int i,int p,vector<int> &v,vector<vector<int>> &dp){
    if(i<0)return 1;
    if(dp[i][p]!=-1)return dp[i][p];
    int g= 0,s=0,e=0;

    if(v[i]==0){
        if(p<m)g= rec(i-1,p+1,v,dp);
        if(p>1)s= rec(i-1,p-1,v,dp);
        e= rec(i-1,p,v,dp);
    }else{
        if(abs(p-v[i])>1)return dp[i][p]= 0;
        else return dp[i][p]= rec(i-1,v[i],v,dp);
    }

    return dp[i][p]= (g%M+s%M+e%M)%M;
}

int32_t main(){
    int n,x;cin>>n>>x;
    m=x;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    int ans=0;
    vector<vector<int>> dp(n,vector<int>(m+1,-1));
    if(v[n-1]==0){
        for(int i=1;i<=m;i++){
            ans = (ans%M + rec(n-2,i,v,dp)%M)%M;
        }
    }else ans=rec(n-2,v[n-1],v,dp)%M;
    cout<<ans<<endl;
}