#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int s1,int s2,int d,vector<int> &v,vector<vector<int>> &dp){
    int M=1e9+7;

    int di=s1-s2;
    if(i<0 && di==d)return 1;
    if(i<0 || di<0)return 0;

    if(dp[i][s1]!=-1)return dp[i][s1];

    int np=rec(i-1,s1,s2,d,v,dp);
    int p=rec(i-1,s1-v[i],s2+v[i],d,v,dp);

    return dp[i][s1]=(p%M+np%M)%M;
}

int tabulation(vector<int>&v,int d){
    int M=1e9+7;
    int sum=0;
    for(auto i:v)sum+=i;

    vector<vector<int>> dp(v.size(),vector<int>(sum+1,0));
    int x=d+sum;
    if(x%2==0 && (x/2) <=sum)dp[0][x/2]++;
    x+=2*v[0];
    if(x%2==0 && (x/2)<=sum)dp[0][x/2]++;

    for(int i=1;i<v.size();i++){
        for(int j=0;j<sum+1;j++){
            int p=0;
            if(j-v[i]>=0)p=dp[i-1][j-v[i]];
            int np=dp[i-1][j];
            dp[i][j]=(p%M + np%M)%M;
        }
    }
    return dp[v.size()-1][sum];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    return tabulation(arr,d);
    for(auto i:arr)sum+=i;
    // vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    // l=rec(n-1,sum,0,d,arr,dp);
}

void solve(){
    int n;cin>>n;
    int d;cin>>d;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    cout<<countPartitions(n,d,v);
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}