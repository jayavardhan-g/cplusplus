//https://leetcode.com/contest/weekly-contest-357/problems/find-the-safest-path-in-a-grid/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    int sd(int i,int j,vector<vector<int>> &v,vector<vector<int>> &dp){
        if(dp[i][j]==-2)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        if(v[i][j]==1)return 0;

        int x=INT_MAX;
        dp[i][j]=-2;
        if(i>0){
            x=min(x, 1+ sd(i-1,j,v,dp));
        }
        if(i<v.size()-1){
            x=min(x, 1+ sd(i+1,j,v,dp));
        }
        if(j>0){
            x=min(x, 1+ sd(i,j-1,v,dp));
        }
        if(j<v.size()-1){
            x=min(x, 1+ sd(i,j+1,v,dp));
        }
        return dp[i][j]=x;
    }

    int rec(int i,int j,vector<vector<int>> &s, vector<vector<int>> &v,vector<vector<int>> &dp){
        if(dp[i][j]==-2)return -1e9;
        if(dp[i][j]!=-1)return v[i][j];
        if(i==v.size()-1 && j==v.size()-1)return dp[i][j]=sd(i,j,v,dp);
        
        int x=0;
        dp[i][j]=-2;
        if(i>0){
            x= max(x, min(s[i][j], s[i-1][j]));
        }
        if(i<v.size()-1){
            x= max(x, min(s[i][j], s[i+1][j]));
        }
        if(j>0){
            x= max(x, min(s[i][j], s[i][j-1]));
        }
        if(j<v.size()-1){
            x= max(x, min(s[i][j], s[i][j+1]));
        }

        return dp[i][j]=x;
    }

    int maximumSafenessFactor(vector<vector<int>>& v) {
        vector<vector<int>> dp(v.size(),vector<int>(v.size(),-1));
        vector<vector<int>> s(v.size(),vector<int>(v.size()));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++)s[i][j]=sd(i,j,v,dp);
        }
        for(auto i:s){
            for(auto j:i)cout<<j<<' ';
            cout<<endl;
        }
        return 0;
    }

int32_t main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>v[i][j];
    cout<<maximumSafenessFactor(v);
}