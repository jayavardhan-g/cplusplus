#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

string rec(int i,int j,string s,string t,vector<vector<string>>&dp){
	string x;
	if(j==-1)return x;
	if(i==0){
		if(t.rfind(s[i],j)<t.length())return x+s[i];
		else return x;
	}

	if(dp[i][j].length()!=0)return dp[i][j];

	string p;
	if(t.rfind(s[i],j)<t.length()){
		p+=s[i]+rec(i-1,t.rfind(s[i],j)-1,s,t,dp);
	}
	string np=rec(i-1,j,s,t,dp);

	return dp[i][j]=p.length()>np.length()?p:np;
}
string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<string>> dp(n,vector<string>(m));
	string k=rec(n-1,m-1,s1,s2,dp);	
	reverse(k.begin(),k.end());
	return k;
}


int32_t main(){
    int x;cin>>x>>x;
    string s;cin>>s;
    string t;cin>>t;
    cout<<findLCS(s.length(),t.length(),s,t)<<endl;
}