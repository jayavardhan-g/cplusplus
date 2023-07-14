//https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
bool rec(int s1, int s2, int i, vector<int> &v,vector<vector<vector<int>>> &dp) {
	if(i<0 && s1==s2)return 1;
	if(i<0)return 0;
	
	if(dp[i][s1][s2]!=-1){
		if(dp[i][s1][s2]==1)return 1;
		else return 0;
	}


  	bool p = rec(s1 + v[i], s2 - v[i], i - 1, v, dp);
  	bool np = rec(s1, s2, i - 1, v, dp);

    if(p||np){
		dp[i][s1][s2]=1;
		return 1;
	}else{
		dp[i][s1][s2]=0;
		return 0;
	}
}

bool canPartition(vector<int> &arr, int n)
{	
	int sum=0;for(auto i:arr)sum+=i;
	vector<vector<vector<int>>> dp(n,vector<vector<int>> (sum+1,vector<int>(sum+1,-1)));
	return rec(0,sum,n-1,arr,dp);
}
int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
        cout<<canPartition(v,n)<<endl;
    }
}