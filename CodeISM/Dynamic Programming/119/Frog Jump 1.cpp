//https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int a[],int dp[]){
    if(dp[i]!=-1)return dp[i];
    if(i==1)return abs(a[1]-a[0]);
    if(i==2)return abs(a[2]-a[0]);


    int x= abs(a[i]-a[i-1]) + rec(i-1,a,dp);
    int y= abs(a[i]-a[i-2]) + rec(i-2,a,dp);

    return dp[i]=min(x,y);
}

int32_t main(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int dpr[n];
    memset(dpr,-1,sizeof(dpr));
    
    cout<<rec(n-1,a,dpr)<<endl;
    return 0;
    int dp[n]={0};
    dp[1]= abs(a[1]-a[0]);
    for(int i=2;i<n;i++){
        int x,y;
        x= dp[i-1] + abs(a[i]-a[i-1]);
        y= dp[i-2] + abs(a[i]-a[i-2]);
        dp[i]= min(x,y);
    }
    cout<<dp[n-1]<<endl;
}