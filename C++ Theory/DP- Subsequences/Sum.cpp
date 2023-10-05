//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 

bool check(int i,int sum,int k,vector<int> &v,vector<vector<int>> &dp){
    if(i<0){
        if(sum==k)return 1;
        else return 0;
    }
    if(sum==k)return 1;
    if (dp[i][sum] != -1) {
      if (dp[i][sum] == 0)
        return 0;
      else
        return 1;
    }
    bool p = 0;
    bool np = check(i - 1, sum, k, v,dp);
    if (sum + v[i] <= k)
      p = check(i - 1, sum + v[i], k, v,dp);

    p = np||p;
    if(p)dp[i][sum]=1;
    else dp[i][sum]=0;

    return p;
}

bool check(int i,int sum,vector<int> &v,vector<vector<int>> &dp){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(i<0)return 0;
    if(dp[i][sum]!=-1){
        if(dp[i][sum])return 1;
        else return 0;
    }
    bool p=0,np;
    np=check(i-1,sum,v,dp);
    p=check(i-1,sum-v[i],v,dp);
    
    if(p|np){dp[i][sum]=1;return 1;}
    else {
        dp[i][sum]=0;return 0;
    }
}

bool tabulation(vector<int> &v,int k){
    vector<vector<bool>> dp(v.size(),vector<bool>(k+1,0));
    for(int i=0;i<v.size();i++)dp[i][0]=1;
    dp[0][v[0]]=1;

    for(int i=1;i<v.size();i++){
        for(int j=1;j<k+1;j++){
            bool p=0,np;
            if(j-v[i]>=0)p=dp[i-1][j-v[i]];
            np=dp[i-1][j];
            dp[i][j]=p||np;
        }
    }
    return dp[v.size()-1][k];
}

bool space(vector<int> &v,int k){
   vector<bool> dp(k+1,0);
   dp[v[0]]=1;
   dp[0]=1;
    
    for(int i=1;i<v.size();i++){
        vector<bool> temp(k+1);
        for(int j=0;j<k+1;j++){
            bool p=0,np;
            if(j-v[i]>=0)p=dp[j-v[i]];
            np=dp[j];
            temp[j]=p||np;
        }
        dp=temp;
    }
    return dp[k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // return check(n-1,0,k,arr,dp);
    // return (n-1,k,arr,dp);
    // return tabulation(arr,k);
    return space(arr,k);
    // return tabulation(arr,k);
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
        int k;cin>>k;
        cout<<subsetSumToK(n,k,v)<<endl;
    }
}