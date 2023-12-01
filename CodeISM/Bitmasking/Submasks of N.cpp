#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    for(int x=n;x>0;x=(x-1)&n)cout<<x<<endl;
}