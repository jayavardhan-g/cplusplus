#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int sol(vector<int> v,int k,int i,vector<int> dp){
    if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
    
    int mini=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j<0)break;
        mini=min(mini,abs(v[i]-v[i-j])+sol(v,k,i-j,dp));
    }
    dp[i]=mini;
    return mini;
}
//tabulation
int tb(vector<int> v,int k){
    vector<int> dp(v.size(),0);
    for(int i=1;i<v.size();i++){
        int ans=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                ans=min(abs(v[i]-v[i-j])+dp[i-j],ans);
            }
        }
        dp[i]=ans;
    }
    return dp[v.size()-1];
}
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> dp(n,-1);
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    // cout<<sol(v,k,n-1,dp);
    cout<<tb(v,k);
}