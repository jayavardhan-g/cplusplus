#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int solve(string s,string t){
	int x=0;
	while(s[x]==t[x] && x<s.length() &&x<t.length()){
		x++;
	}
	return x;
}

int lcs(string &s, string &t){
	// vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
	// return rec(s.length()-1,t.length()-1,0,s,t,dp);
	int ans=0;
	for(int i=0;i<s.length();i++){
		int x=-1;
		while(t.find(s[i],x+1)<t.size()){
			ans=max( ans, solve(s.substr(i), t.substr(t.find(s[i],x+1))) );
			x=t.find(s[i],x+1);
		}
	}
	return ans;
}

int32_t main(){
    string s,t;cin>>s>>t;
    cout<<lcs(s,t);
}