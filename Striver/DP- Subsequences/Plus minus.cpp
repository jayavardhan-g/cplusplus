#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int target,vector<int> &v,int sum,vector<vector<int>> &dp){
    if(i==0){
        if(target-v[i]==0&&target+v[i]==0)return 2;
        else if(target-v[i]==0 || target+v[i]==0)return 1;
        else return 0;
    }
    if(dp[i][target+sum]!=-1)return dp[i][target+sum];
    
    int p=rec(i-1,target+v[i],v,sum,dp);
    int np=rec(i-1,target-v[i],v,sum,dp);

    return dp[i][target+sum]=p+np;
}

void solve(){
    int n;cin>>n;
    int t;cin>>t;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];

    int sum=0;for(auto i:v)sum+=i;
    vector<vector<int>> dp(n,vector<int> (abs(t+sum)+abs(t-sum)+2,-1));
    cout<< rec(n-1,t,v,sum,dp)<<endl;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}