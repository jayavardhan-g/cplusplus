// Check if ith bit of a given number n is 0 or 1
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<64;i++){
        if(n&(1LL<<i))ans++;
    }
    cout<<ans;
}