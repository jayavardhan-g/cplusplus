#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int M=1e9+7;

pair<int,int> rec(int i,int j,string &s,vector<vector<pair<int,int>>> &dp){
    pair<int,int> p;
    if(dp[i][j].first!=-1)return dp[i][j];
    if(i==j){
        if(s[i]=='T')p={0,1};
        else p={1,0};
        return p;
    }
    p={0,0};
    for(int k=i+1;k<j;k+=2){
        int x0= rec(i,k-1,s,dp).first;
        int x1= rec(i,k-1,s,dp).second;
        int y0= rec(k+1,j,s,dp).first;
        int y1= rec(k+1,j,s,dp).second;
        
        // if(s[k]=='|')cout<<'|'<<endl;
        if(s[k]=='&'){
            p.first= (p.first%M + (x0%M*y1%M)%M + (x1%M*y0%M)%M + (x0%M*y0%M)%M)%M;
            p.second= (p.second%M + ((x1%M)*(y1%M))%M)%M;
        }
        if(s[k]=='|'){
            p.first= (p.first%M + (x0%M * y0%M)%M)%M;
            p.second= (p.second%M + (x0%M * y1%M)%M + (x1%M*y0%M)%M + (x1%M*y1%M)%M)%M;
        }
        if(s[k]=='^'){
            p.first= (p.first%M + (x1%M * y1%M)%M + (x0%M *y0%M)%M )%M;
            p.second= (p.second%M + (x1%M * y0%M)%M + (x0%M * y1%M)%M)%M;
        }
    }
    return dp[i][j]=p;
}
int evaluateExp(string & exp) {
    vector<vector<pair<int,int>>> dp(exp.length(),vector<pair<int,int>>(exp.length(),{-1,0}));
    // cout<<"answer"<<(1^1)<<(0^0)<<(1^0)<<(0^1)<<"end";
    return rec(0,exp.length()-1,exp,dp).second;
}
int32_t main(){
    string s;
    cin>>s;
    cout<<evaluateExp(s)<<endl;
}