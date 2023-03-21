// Check if ith bit of a given number n is 0 or 1
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int i;cin>>i;
    int x=pow(2,i);
    int y=1<<i;
    if((n&y)==x)cout<<1;
    else cout<<0;
}