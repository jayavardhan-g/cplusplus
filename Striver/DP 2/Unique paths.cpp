//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int solve(int n,int m, int i,int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==0 && j==0)return 1;
    int fs=0,ss=0;
    if(i>0){
        fs=solve(n,m,i-1,j,dp);
    }
    if(j>0){
        ss=solve(n,m,i,j-1,dp);
    }
    return dp[i][j]=fs+ss;
}

int tb(int n,int m){
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0)continue;
            int fs=0,ss=0;
            if(i>0)fs=dp[i-1][j];
            if(j>0)ss=dp[i][j-1];
            dp[i][j]=fs+ss;
        }
    }
    return dp[n-1][m-1];
}

int space(int n,int m){
    vector<int> prev_row(m,0);
    int temp=1;
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        temp=0;
        for(int j=0;j<m;j++){
            if(i==0&&j==0)temp=1;
            int fs=0,ss=0;
            fs=prev_row[j];
            ss=temp;
            curr[j]=fs+ss;
            temp=curr[j];
        }
        prev_row=curr;
    }
    return prev_row[m-1];
}

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<solve(n,m,n-1,m-1,dp);
    // cout<<tb(n,m);
    cout<<space(n,m);
}