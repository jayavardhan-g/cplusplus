#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
string rec(int i,int j,string s,string t,vector<vector<string>>&dp){
	string x;
	if(i==0){
		if(t.rfind(s[i])<t.length())return x+s[i];
		else return x;
	}
	if(j==-1)return x;
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
	return rec(s1.length()-1,s2.length()-1,s1,s2,dp);	
}
int32_t main(){
    int x;
    cin>>x>>x;
    string s;cin>>s;
    string t;cin>>t;
    cout<<t.find(s)+1;

}