//https://www.hackerearth.com/challenges/competitive/august-clash/algorithm/mehta-and-the-tricky-triplets/description/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int n;
// int a[100001];
int p[100001];
int dp[100001][4][1LL<<4];

int solve(int i,int nu,int mask){
    if(i>=n){
        if(nu==3 && mask)return 1;
        return 0;
    }
    if(dp[i][nu][mask]!=-1)return dp[i][nu][mask];

    int ans = 0;
    ans += solve(i+1,nu,mask);
    if(nu<3)ans += solve(i+1,nu+1, mask&p[i]);

    return dp[i][nu][mask]= ans;
}

int32_t main(){
    cin>>n;
    memset(p,0,sizeof(p));
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int temp = 0;
        while(x){
            if(x%10==2)temp = temp|(1LL<<0);
            if(x%10==3)temp = temp|(1LL<<1);
            if(x%10==5)temp = temp|(1LL<<2);
            if(x%10==7)temp = temp|(1LL<<3);
            x/=10;
        }
        p[i]=temp;
    }

    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,15);
}