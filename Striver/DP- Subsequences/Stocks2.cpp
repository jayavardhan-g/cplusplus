#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int ms=0;

long solve(vector<long> &v,int n){
    long ans=0,minn=v[0];
    for(int i=0;i<n;i++){
        minn=min(v[i],minn);
        if(v[i]>minn){
            ans+=v[i]-minn;
            minn=v[i];
        }
    }
    return ans;
}

int rec(int i,int f,vector<long> &v,vector<vector<int>> &dp){
    if(i<0 && f==1)return -1e7;
    if(i<0)return 0;
    if(dp[i][f]!=-1)return dp[i][f];
    int bs=0,n=0;
    if(f==1){
        bs=-v[i]+rec(i-1,0,v,dp);
    }else{
        bs=v[i]+rec(i-1,1,v,dp);
    }
    n=rec(i-1,f,v,dp);
    return dp[i][f]=max(bs,n);
}

long maxProfit(vector<long>& prices) {
    // return solve(prices,prices.size());
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    return rec(prices.size()-1,0,prices,dp);
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long> v(n);for(int i=0;i<n;i++)cin>>v[i];
        cout<<maxProfit(v)<<endl;
    }
}