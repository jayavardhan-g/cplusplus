#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int sol(int i){
    if(i==0)return 1;
    if(i==1)return 1;
    int l=sol(i-1);
    int r=sol(i-2);
    return l+r;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<sol(n)<<endl;
    }
}