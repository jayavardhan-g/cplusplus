#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> solve(vector<int> v,int n){
	vector<int> dp(n,1),f(n);
	for(int i=0;i<n;i++)f[i]=i;
	int ans=0, ind=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				if(1+dp[j]>dp[i]){
					f[i]=j;
					dp[i]=1+dp[j];
				}
			}
			if(dp[i]>ans){
				ans=dp[i];
				ind=i;
			}
		}
	}
    for(auto i:dp)cout<<i<<' ';
    cout<<endl;
    for(auto i:f)cout<<i<<' ';
    cout<<endl;
    cout<<ind<<endl;
	vector<int> a;
	int i=ind;
	while(f[i]!=i){
		a.push_back(v[i]);
		i=f[i];
	}
    a.push_back(v[i]);
	reverse(a.begin(),a.end());
	return a;
}

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// return tabulation(arr,n);
	return solve(arr,n);
}


int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
	
    vector<int> x=printingLongestIncreasingSubsequence(v,n);
    for(auto i:x)cout<<i<<' ';
}