#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int j,string s,string t,vector<vector<int>> &dp){
    if(j<0)return 1;
    if(i<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int p=0;
    if(s[i]==t[j])p=rec(i-1,j-1,s,t,dp);

    int np=rec(i-1,j,s,t,dp);
    return dp[i][j]=p+np;
}
int tabulation(string s,string t){
    int M=1e9+7;
    vector<vector<int>> dp(s.length()+1,vector<int> (t.length()+1,0));
    for(int i=0;i<s.length()+1;i++)dp[i][0]=1;
    
    for(int i=1;i<s.length()+1;i++){
        for(int j=1;j<t.length()+1;j++){
            int p=0;
            if(s[i-1]==t[j-1])p=dp[i-1][j-1];
            int np=dp[i-1][j];
            dp[i][j]=(p%M+np%M)%M;
        }
    }
    // for(auto i:dp){for(auto j:i)cout<<j<<' ';cout<<endl;}
    return dp[s.length()][t.length()];
}
int space(string s,string t){
    int M=1e9+7;
    vector<int> prev(t.length()+1,0),curr(t.length()+1,0);
    prev[0]=1;
    for(int i=1;i<s.length()+1;i++){
        for(int j=t.length();j>=1;j--){
            int p=0;
            if(s[i-1]==t[j-1] && j>0)p=prev[j-1];
            int np=prev[j];
            prev[j]=(p%M+np%M)%M;
        }
        // for(auto k:prev)cout<<k<<' ';
        // cout<<endl;
    }
    return prev[t.length()];
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    return space(s,t);
    return tabulation(s,t);
    vector<vector<int>> dp(ls,vector<int> (lt,-1));
    return rec(ls-1,lt-1,s,t,dp);
} 

int32_t main(){
    int t;cin>>t;
    while(t--){
        int x;cin>>x>>x;
        string s;cin>>s;
        string t;cin>>t;
        cout<<subsequenceCounting(t,s,t.length(),s.length());
        cout<<endl;   
    }
}
