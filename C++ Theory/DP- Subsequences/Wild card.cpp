//https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool rec(int i,int j,string &s,string &t,vector<vector<bool>> &dp){
   if(j<0 && i<0) return 1;
   if(j<0){
    for(i;i>=0;i--){
        if(s[i]!='*')return 0;
    }
    return 1;
   }
   if(i<0)return 0;
   
   if(dp[i][j]!=0)return 1;

   bool m=0,q=0;
   if(s[i]==t[j]){
      m=rec(i-1,j-1,s,t,dp);
   }
   bool a=0;
   if(s[i]=='*'){
      a=rec(i-1,j,s,t,dp)||rec(i,j-1,s,t,dp);
   }
   if(s[i]=='?'){
      q=rec(i-1,j-1,s,t,dp);
   }

   return dp[i][j]=m||a||q;
}

bool tabulation(string s,string t){
    vector<vector<bool>> dp(s.length()+1,vector<bool>(t.length()+1,0));
    dp[0][0]=1;
    for(int i=1;i<s.length()+1;i++){
        int x=i;
        for(x;x>=1;x--){
            if(s[x-1]!='*')break;
        }
        if(x==-1)dp[i][0]=1;

        for(int j=1;j<t.length()+1;j++){
               bool m=0,q=0,a=0;
                if(s[i-1]==t[j-1]){
                    m=dp[i-1][j-1];
                }
                if(s[i-1]=='*'){
                    a=dp[i-1][j]||dp[i][j-1];
                }
                if(s[i-1]=='?'){
                    q=dp[i-1][j-1];
                }

                dp[i][j]=m||a||q;
        }
    }

    return dp[s.length()][t.length()];
}

bool wildcardMatching(string pattern, string text)
{  
    return tabulation(pattern,text);
   vector<vector<bool>> dp(pattern.length(),vector<bool> (text.length(),0));
   return rec(pattern.length()-1,text.length()-1,pattern,text,dp);
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        cout<<wildcardMatching(s,t)<<endl;
    }
}