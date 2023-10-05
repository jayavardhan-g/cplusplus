#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int mem(int i,vector<int> v,vector<int>&dp){
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];

    int p,np;
    p=v[i]+mem(i-2,v,dp);
    np=mem(i-1,v,dp);
    dp[i]=max(p,np);
    return dp[i];
}
int tb(vector<int> v){
    vector<int> dp(v.size(),0);

    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);

    for(int i=2;i<v.size();i++){
        int p=v[i]+dp[i-2];
        int np=dp[i-1];
        dp[i]=max(p,np);
    }
    return dp[v.size()-1];
}
int space(vector<int> v){
    int p2,p1;
    p2=v[0];
    p1=max(v[0],v[1]);
    for(int i=2;i<v.size();i++){
        int np=p1;
        int p=v[i]+p2;
        int curr=max(p,np);
        p2=p1;
        p1=curr;
    }
    return p1;
}
int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    vector<int> dp(n,-1);
    // cout<<mem(n-1,v,dp);
    // cout<<tb(v);
    cout<<space(v);
}