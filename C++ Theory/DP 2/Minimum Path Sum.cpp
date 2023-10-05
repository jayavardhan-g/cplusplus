//www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
#include<bits/stdc++.h>
using namespace std;
#define int long long

int mem(int i,int j, vector<vector<int>> &v, vector<vector<int>> &dp){
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==0 && j==0)return v[i][j];
    int fs=INT_MAX,ss=INT_MAX;
    if(i>0){
        fs=v[i][j]+mem(i-1,j,v,dp);
    }
    if(j>0){
        ss=v[i][j]+mem(i,j-1,v,dp);
    }
    return dp[i][j]=min(fs,ss);
}

int tb(vector<vector<int>> v,int n,int m){
    vector<vector<int>> dp(n,vector<int> (m,0));
    dp[0][0]=v[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)continue;
            int fs=INT_MAX,ss=INT_MAX;
            if(i>0)fs=v[i][j]+dp[i-1][j];
            if(j>0)ss=v[i][j]+dp[i][j-1];
            dp[i][j]=min(fs,ss);
        }
    }
    return dp[n-1][m-1];
}
int space(vector<vector<int>> v,int n,int m){
    vector<int> pre_row(m,0);
    pre_row[0]=v[0][0];
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<m;j++){
            if(i==0&&j==0){temp=pre_row[j];continue;}
            int fs=INT_MAX,ss=INT_MAX;
            if(i>0)fs=v[i][j]+pre_row[j];
            if(j>0)ss=v[i][j]+temp;
            pre_row[j]=min(fs,ss);
            temp=pre_row[j];
        }
    }
    return pre_row[m-1];
}
int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>v[i][j];
    }
    vector<vector<int>> dp(n,vector<int> (m,-1));
    // cout<<mem(v.size()-1,v[0].size()-1,v,dp);
    // cout<<tb(v,n,m);
    cout<<space(v,n,m);
}