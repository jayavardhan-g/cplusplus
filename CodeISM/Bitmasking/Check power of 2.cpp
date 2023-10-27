#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    if((n- (n&(-n)))==0)cout<<"Yes";
    else cout<<"NO";
}