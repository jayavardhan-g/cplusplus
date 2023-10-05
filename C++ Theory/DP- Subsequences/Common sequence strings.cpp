#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int rec(int i,int j,string s,string t,vector<vector<int>> &dp){
	if(i==s.length()-1){
		if(t.find(s[i],j)<t.length())return 1;
		else return 0;
	}
	if(j==t.size())return 0;
	if(dp[i][j]!=-1)return dp[i][j];

	int p=0;

	if(t.find(s[i],j)<t.size()){
		p=1+rec(i+1,t.find(s[i],j)+1,s,t,dp);
	}
    
	int np=rec(i+1,j,s,t,dp);

	return dp[i][j]=max(p,np);
}

int tabulation(string s,string t){
	vector<vector<int>> dp(s.length(),vector<int> (t.length(),0));

	for(int i=0;i<t.length();i++){
		if(t.find(s[s.length()-1],i)<t.length())dp[s.length()-1][i]++;
	}

	for(int i=s.length()-2;i>=0;i--){
		for(int j=0;j<t.length();j++){
			int p=0;
			if(t.find(s[i],j)<t.size()){
				p=1;
				if((t.find(s[i],j)+1)<t.size())p+=dp[i+1][t.find(s[i],j)+1];
			}
			// if(t.find(s[i],j)<t.size())p++;
			// if(t.find(s[i],j)+1<t.size())p+=dp[i+1][t.find(s[i],j)+1];
			
			int np=dp[i+1][j];

			dp[i][j]=max(p,np);
		}
	}
	return dp[0][0];
}
int lcs(string s, string t)
{	
	return tabulation(s,t);
	vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
}

int32_t main(){
    string s;cin>>s;
    string t;cin>>t;
    cout<<lcs(s,t);
}