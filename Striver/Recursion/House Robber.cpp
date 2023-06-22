#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int money(vector<int> v, int i, bool f,vector<int> &dp) {
    if (i>= v.size())return 0;
    if(i==v.size()-1 && f)return 0;
    if(dp[i]!=-1)return dp[i];
    
    int fs,ss;
    if(i==0)fs=v[i]+money(v,i+2,1,dp);
    else fs=v[i]+money(v,i+2,f,dp);
    
    ss=money(v,i+1,f,dp);

    if(fs>ss)return dp[i]=fs;
    else return dp[i]=ss;
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    vector<int> dp(n,-1);
    cout<<money(v,0,0,dp);
}