//https://codeism.contest.codeforces.com/group/qXv2tukHZE/contest/309847/problem/E
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve(){
    int n;cin>>n;
    int su=0,xo=0;
    vector<int> v(n);for(int i=0;i<n;i++){
        cin>>v[i];
        su+= v[i];
        xo^= v[i];
    }

    int l= su;
    int r= xo;
    int z=0;
    if(r&1){
        z= z|1;
    }

    for(int i=0;i<63;i++){
        bool aa= l &(1LL<<i);
        bool xx= r &(1LL<<(i+1));

        if(aa){
            if(xx){

            }
        }
    }
}

int32_t main(){
    int t;cin>>t;
    while(t--)solve();
}