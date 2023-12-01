//https://atcoder.jp/contests/dp/tasks/dp_u
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int a[16][16];

int solve(int mask){
    if(mask==0)return 0;
    int ans=0;
    vector<int> v;

    for(int i=0;i<16;i++){
        if(mask & (1LL<<i))v.push_back(i);
    }
    int temp=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            temp+= a[i][j];
        }
    }
    ans= max(temp,ans);
    for(int i=mask-1;i>0;i= (i-1)&mask){
        ans=max(ans, solve(i));
    }

    return ans;
}

int32_t main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    int x = (1LL<<n)-1;
    cout<<solve(x);
}