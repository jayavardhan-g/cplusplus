//https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int rec(int i,int s1,int s2,vector<int> &v,vector<vector<int>> &dp){
	if(i<0)return abs(s1-s2);
	if(dp[i][s2]!=-1)return dp[i][s2];


	int p=rec(i-1,s1+v[i],s2-v[i],v,dp);
	int np=rec(i-1,s1,s2,v,dp);

	return dp[i][s2]=min(p,np);
}

int tabulation(vector<int>&v){
	int sum=0;
	for(auto i:v)sum+=i;
	vector<vector<int>> dp(v.size()+1,vector<int> (sum+1,0));

	for(int i=0;i<sum+1;i++)dp[0][i]=abs(sum-2*i);
    for(auto i:dp){for(auto j:i)cout<<j<<' '; cout<<endl;}
	for(int i=1;i<3;i++){
		for(int j=0;j<sum+1;j++){
			int p=INT_MAX;
			if(j-v[i]>=0)p=dp[i-1][j-v[i]];
			int np=dp[i-1][j];
			dp[i][j]=min(p,np);
		}
	}
    cout<<endl;
    for(auto i:dp){for(auto j:i)cout<<j<<' '; cout<<endl;}
    
	return dp[v.size()][sum];
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// int sum=0;
	// for(auto i:arr)sum+=i;
	// vector<vector<int>> dp(n,vector<int> (sum+1,-1));
	// return rec(n-1,0,sum,arr,dp);
	return tabulation(arr);
}
void solve(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    cout<<minSubsetSumDifference(v,n)<<endl;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}