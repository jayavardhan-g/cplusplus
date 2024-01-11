//https://codeism.contest.codeforces.com/group/qXv2tukHZE/contest/309847/problem/F
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    int a=v[0],o=v[0];
    for(int i=1;i<n;i++){
        a= a&v[i];
        o= o|v[i];
    }
    cout<<a<<' '<<o<<endl;
    int ans =0;

    for(int i=0;i<64;i++){
        if(a&(1LL<<i)){
            if(o&(1LL<<i)){
                ans = ans|(1LL<<i);
            }
        }
    }

    int maxx= INT_MIN;
    for(int i=0;i<n;i++){
        maxx = max(maxx, ans^v[i] );
    }
    cout<<maxx<<endl<<ans;
}