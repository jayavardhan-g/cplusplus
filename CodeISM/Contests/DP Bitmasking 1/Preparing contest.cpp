//https://codeism.contest.codeforces.com/group/qXv2tukHZE/contest/309847/problem/D
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> v;
int dp[1LL<<15];

int solve(int mask){
    return 0;
}

int32_t main(){
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    int ans= 0;
    v.resize(n);for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    // cout<<(1LL<<2);
    for(int i=0;i<(1LL<<n);i++){
        if(__builtin_popcount(i)>=2){
            int sum=0;
            int maxx=INT_MIN,minn=INT_MAX;
            for(int j=0;j<n;j++){
                if( i&(1<<j) ){
                    sum+=v[j];
                    maxx= max(maxx,v[j]);
                    minn= min(minn,v[j]);
                }
            }
            if(sum>=l && sum<=r && maxx-minn>=x) ans++;
        }
    }
    cout<<ans<<endl;
}