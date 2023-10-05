//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
//recursive
int sol(vector<int> v,int i,vector<int> &dp){
    if(dp[i]!=-1)return dp[i];
    if(i==0)return 0;
    if(i==1)return abs(v[i]-v[i-1]);
    int fs=abs(v[i]-v[i-1])+sol(v,i-1,dp);
    int ss=abs(v[i]-v[i-2])+sol(v,i-2,dp);
    return dp[i]=min(fs,ss);
}

//tabulation
int sol(vector<int>v){
    int n=v.size();
    vector<int> dp(n,0);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    for(int i=2;i<n;i++){
        int a1=abs(v[i]-v[i-1])+dp[i-1];
        int a2=abs(v[i]-v[i-2])+dp[i-2];
        dp[i]=min(a1,a2);
    }
    return dp[n-1];
}
//space optimization
int so(vector<int> v){
    int n=v.size();
    int prev2=0;
    int prev1=abs(v[1]-v[0]);
    for(int i=2;i<n;i++){
        int a1=abs(v[i]-v[i-1])+prev1;
        int a2=abs(v[i]-v[i-2])+prev2;
        int curr=min(a1,a2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> dp(n,-1);
        vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
        // cout<<sol(v,n-1,dp)<<endl;
        // cout<<sol(v)<<endl;
        cout<<so(v)<<endl;
    }
}