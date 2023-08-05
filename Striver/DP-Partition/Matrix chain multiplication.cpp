#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int j,vector<int> &v,vector<vector<int>> &dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        ans=min(ans, v[i-1]*v[k]*v[j] + rec(i,k,v,dp) + rec(k+1,j,v,dp));
    }
    return dp[i][j]=ans;
}

int tabulation(vector<int> &v,int n){
    vector<vector<int>> dp(n,vector<int> (n,0));
    
    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<n;j++){
            if(i==j){
                continue;
            }
            int ans=INT_MAX;
            for(int k=i;k<j;k++){
                ans=min(ans, v[i-1]*v[k]*v[j] + dp[i][k] + dp[k+1][j]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][n-1];
}


int matrixMultiplication(vector<int> &v, int n){
    return tabulation(v,n);
    vector<vector<int>> dp(n,vector<int> (n,-1));
    return rec(1,n-1,v,dp);
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<matrixMultiplication(v,n);
    }
}