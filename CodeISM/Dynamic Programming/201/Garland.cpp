#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int v[101];
int dp[101][100][100][3];

int rec(int i,int p,int e,int o){
    if(i<0)return 0;
    if(dp[i][e][o][p]!=-1)return dp[i][e][o][p];
    int ans=1e5;
    if(v[i]==0){
        if(p==0){
            if(e>0)ans = min(ans, rec(i-1,2,e-1,o));
            if(o>0)ans = min(ans, rec(i-1,1,e,o-1));
        }
        if(p==1){
            if(e>0 )ans = min(ans,1+ rec(i-1,2,e-1,o));
            if(o>0)ans = min(ans, rec(i-1,1,e,o-1));
        }
        if(p==2){
            if(e>0)ans = min(ans, rec(i-1,2,e-1,o));
            if(o>0)ans = min(ans,1+ rec(i-1,1,e,o-1));
        }
    }else{
        if(p==0){
            ans =rec(i-1,v[i],e,o);
        }else{
            if(v[i]!=p){
                ans= 1+ rec(i-1,v[i],e,o);
            }else{
                ans= rec(i-1,v[i],e,o);
            }
        }
    }
    return dp[i][e][o][p]=ans;
}

int32_t main(){
    int n;cin>>n;
    memset(v,0,sizeof(v));
    memset(dp,-1,sizeof(dp));
    int o = (n+1)/2, e= n/2;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x==0)continue;
        else if(x%2==0){
            e--;
            v[i]=2;
        }else{
            o--;
            v[i]=1;
        }
    }
    // for(int i=0;i<n;i++)cout<<v[i]<<' ';
    // cout<<endl<<e<<o<<endl;

    cout<<rec(n-1,0,e,o);    
}