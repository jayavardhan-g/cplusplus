//https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int Mm=1e9+7;

int solve(int n,int m, int i,int j,vector<vector<int>> &v,vector<vector<int>> &dp){
    if(dp[i][j]!=-1)return dp[i][j];
    if(v[i][j]==-1)return dp[i][j]=0;
    if(i==0 && j==0)return 1;
    
    int fs=0,ss=0;
    if(i>0){
        fs=solve(n,m,i-1,j,v,dp);
    }
    if(j>0){
        ss=solve(n,m,i,j-1,v,dp);
    }
    return dp[i][j]=(fs%Mm+ss%Mm)%Mm;
}
int tb(int n,int m,vector<vector<int>> &v){
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0)continue;
            if(v[i][j]==-1)continue;
            int fs=0,ss=0;
            if(i>0)fs=dp[i-1][j];
            if(j>0)ss=dp[i][j-1];
            dp[i][j]=(fs%Mm+ss%Mm)%Mm;
        }
    }
    return dp[n-1][m-1];
}

int space(int n,int m,vector<vector<int>> &v){
    vector<int> prev_row(m,0);
    int temp=1;
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        temp=0;
        for(int j=0;j<m;j++){
            if(i==0&&j==0)temp=1;
            if(v[i][j]==-1){temp=0;continue;}
            int fs=0,ss=0;
            fs=prev_row[j];
            ss=temp;
            curr[j]=(fs%Mm+ss%Mm)%Mm;
            temp=curr[j];
        }
        prev_row=curr;
    }
    return prev_row[m-1];
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int m;cin>>m;
        vector<vector<int>> v(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cin>>v[i][j];
        }
        vector<vector<int>> dp(n,vector<int> (m,-1));
        cout<<solve(n,m,n-1,m-1,v,dp)<<endl;
        cout<<space(n,m,v)<<endl;
        cout<<tb(n,m,v)<<endl;
    }
}