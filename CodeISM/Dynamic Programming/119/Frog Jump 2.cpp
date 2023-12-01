#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int k;

int rec(int i,int h[],int dp[]){
    if(dp[i]!=-1)return dp[i];
    if(i==0)return 0;

    int x = INT_MAX;
    for(int j=1;j<=k && i-j>=0 ;j++){
        x= min(x, abs(h[i]-h[i-j]) + rec(i-j,h,dp) );
    }
    return dp[i]=x;
}

int32_t main(){
    int n;cin>>n>>k;
    int h[n];for(int i=0;i<n;i++)cin>>h[i];

    //topdown
    int dpr[n];memset(dpr,-1,sizeof(dpr));
    cout<<rec(n-1,h,dpr);
    return 0;

    //iterative
    int dp[n];
    for(int i=1;i<n;i++)dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=1;i-j>=0&& j<=k ;j++){
            dp[i]= min(dp[i], dp[i-j]+ abs(h[i]-h[i-j]));
        }
    }
    cout<<dp[n-1]<<endl;
}