//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int mem(int i,vector<vector<int>> v, vector<vector<int>> dp, int l){
    if(i==0){
        int r=INT_MIN;
        for(int j=0;j<3;j++){
            if(j!=l)r=max(r,v[i][j]);
        }
        return r;
    }
    if(dp[i][l]!=-1)return dp[i][l]; 
    int r=INT_MIN;
    for(int j=0;j<3;j++){
        if(j!=l){
            r=max(r,v[i][j]+mem(i-1,v,dp,j));
        }
    }
    dp[i][l]=r;
    return r;
}

int tb(vector<vector<int>> &v,int n){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    for(int i=0;i<4;i++){
        int r=0;
        for(int j=0;j<3;j++){
            if(j!=i)r=max(r,v[0][j]);
        }
        dp[0][i]=r;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            int r=0;
            for(int k=0;k<3;k++){
                if(k!=j)r=max(r,v[i][k]+dp[i-1][k]);
            }
            dp[i][j]=r;
        }
    }

    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

int space(vector<vector<int>> &v,int n){
    vector<int> dp(3);
    dp[0]=max(v[0][1],v[0][2]);
    dp[1]=max(v[0][0],v[0][2]);
    dp[2]=max(v[0][1],v[0][0]);

    for(int i=1;i<n;i++){
        vector<int> temp(3,0);
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k!=j)temp[j]=max(temp[j],v[i][k]+dp[k]);
            }
        }
        dp=temp;
    }

    return max(dp[0],max(dp[1],dp[2]));
}

int32_t main(){
    int n;cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        vector<int> temp(3);
        for(int j=0;j<3;j++){
            cin>>temp[j];
        }
        v.push_back(temp);
    }
    vector<vector<int>> dp(n,{-1,-1,-1,-1});
    // cout<<mem(n-1,v,dp,3);
    cout<<tb(v,n);
}
