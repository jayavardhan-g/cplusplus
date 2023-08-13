#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int ans=0;
    for(int i=0;i<16;i++){
        int x,y;
        cin>>x>>y;
        ans+=x*y;
    }
    cout<<ans;
}