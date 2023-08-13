#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int M=1e9+7;
int rec(int i,int S,vector<int> &v,vector<vector<int>>&dp){
	if(S<0)return 0;
	if(i<0 && S==0)return 1;
	if(i<0)return 0;
	if(dp[i][S]!=-1)return dp[i][S];

	int p,np;
	p= rec(i-1,S-v[i],v,dp);
	np = rec(i-1, S, v, dp);
	
	return dp[i][S]= (p%M + np%M)%M;
}
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    vector<vector<int>> dp(v.size(),vector<int>(k+1,-1));
	cout<<rec(v.size()-1,k,v,dp);
}