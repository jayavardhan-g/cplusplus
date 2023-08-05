#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int j,vector<int> v,vector<vector<int>>&dp){
    if(i<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int x=0;
    if(j==v.size())x=1e6;
    else x=v[j];
    int l=rec(i-1,j,v,dp);
    if(v[i]<x)l=max(l, 1+rec(i-1,i,v,dp));

    return dp[i][j]=l;
}

int search(vector<int> v,int x){
    int lo=0,hi=v.size()-1;
    int ans=-1;
    int m;
    while(lo<=hi){
        m=lo+(hi-lo)/2;
        if(v[m]>=x){
            ans=m;
            hi=m-1;
        }else{
            lo=m+1;
        }
    }
    return ans;
}

int bs(vector<int> a,int n){
    vector<int> v;

    for(int i=0;i<n;i++){
        if(search(v,a[i])==-1)v.push_back(a[i]);
        else{
            v[search(v,a[i])]=a[i];
        }
    }
    return v.size();
}

int longestIncreasingSubsequence(vector<int> arr, int n)
{   
    return bs(arr,n);
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return rec(n-1,n,arr,dp);
}


int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    cout<<longestIncreasingSubsequence(v,n);
}