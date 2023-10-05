//https://www.codingninjas.com/codestudio/problems/triangle_1229398
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int M=1e9+7;
int mem(vector<vector<int>> &v, vector<vector<int>> &dp, int i,int j,int n){
    if(j>i || i>=n)return M;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==n-1)return v[i][j];

    int fs=v[i][j]+mem(v,dp,i+1,j,n);
    int ss=v[i][j]+mem(v,dp,i+1,j+1,n);
    return dp[i][j]=min(fs,ss);
}
int tb(vector<vector<int>> &v){
	int n=v.size();
	vector<vector<int>>dp(n,vector<int>(n,0));
	for(int i=0;i<n;i++)dp[0][i]=v[n-1][i];

	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			int fs=v[n-1-i][j]+dp[i-1][j];
			int ss=v[n-1-i][j]+dp[i-1][j+1];
			dp[i][j]=min(fs,ss);
		}
	}
	return dp[n-1][0];
}
int space(vector<vector<int>> &v){
	int n=v.size();
	vector<int> sp(n,0);
	for(int i=0;i<n;i++)sp[i]=v[n-1][i];
	
	for(int i=1;i<n;i++){
		vector<int> curr(n,0);
		for(int j=0;j<n-i;j++){
			int fs=v[n-1-i][j]+sp[j];
			int ss=v[n-1-i][j]+sp[j+1];
			curr[j]=min(fs,ss);
		}
		sp=curr;
	}
	return sp[0];
}
int32_t main(){
    int n;cin>>n;
    vector<vector<int>>v (n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>v[i][j];
        }
    }
    for(auto i:v){
        for(auto j:i)cout<<j<<' ';
        cout<<endl;
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));

    // cout<<mem(v,dp,0,0,n);
    // cout<<tb(v);
    cout<<space(v);

}