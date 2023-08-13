#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool check(int i,int j,string &s){
    for(int k=0;k<(j-i+1)/2; k++){
        if(s[i+k]!=s[j-k])return 0;
    }
    return 1;
}
int rec(int i,int j,string &s,vector<vector<int>> &dp){
    if(dp[i][j]!=-1)return dp[i][j];
    if(check(i,j,s))return 0;

    int x=INT_MAX;
    for(int k=i;k<j;k++){
        x=min(x, 1+ rec(i,k,s,dp) + rec(k+1,j,s,dp));
    }
    return dp[i][j]=x;
}
bool check(string t){
    for(int i=0;i<(t.length()/2);i++){
        if(t[i]!=t[t.length()-1-i])return 0;
    }
    return 1;
}
int rec2(int i,string &s, vector<int> &dp){
    if(i==s.length())return -1;
    if(dp[i]!=-1)return dp[i];

    string t="";
    int x=INT_MAX;
    for(int k=i;k<s.length();k++){
        t+=s[k];
        if(check(t)){
            x=min(x, 1+rec2(k+1,s,dp));
        }
    }
    return dp[i]=x;
}

int palindromePartitioning(string s)
{   
    vector<int> dp2(s.length(),-1);
    return rec2(0,s,dp2);
    vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
    return rec(0,s.length()-1,s,dp);
}

int32_t main(){
    string s;cin>>s;
    cout<<palindromePartitioning(s);
}