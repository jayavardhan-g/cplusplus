//https://www.codingninjas.com/studio/problems/edit-distance_630420
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int j,string s,string t,vector<vector<int>> &dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    
    if(s[i]==t[j])return dp[i][j]=rec(i-1,j-1,s,t,dp);

    int r=1+rec(i-1,j-1,s,t,dp);
    int e=1+rec(i-1,j,s,t,dp);
    int in=1+rec(i,j-1,s,t,dp);
    
    return dp[i][j]=min(r,min(e,in));
}
int tabulation(string s,string t){
    int  n=s.length(),m=t.length();
    
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<m+1;i++)dp[0][i]=i;
    for(int i=0;i<n+1;i++)dp[i][0]=i;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
                continue;
            }
            dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[n][m];
}

int space(string s,string t){
    int  n=s.length(),m=t.length();
    
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int i=0;i<m+1;i++)prev[i]=i;

    for(int i=1;i<n+1;i++){
        curr[0]=i;
        for(int j=1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
                curr[j]=prev[j-1];
                continue;
            }
            curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
        }
        prev=curr;
        curr=vector<int>(m+1,0);
    }
    return prev[m];
}
int editDistance(string s, string t)
{   
    return space(s,t);
    vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
    int x=rec(s.length()-1,t.length()-1,s,t,dp);
    return x;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        string t;cin>>t;
        cout<<editDistance(s,t)<<endl;
    }
}