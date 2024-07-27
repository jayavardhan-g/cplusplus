//https://www.spoj.com/problems/JNEXT/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    int s=0;
    // stack<int>st;
    for(int i=n-1;i>=0;i--){
        if( i+1!=n && a[i]<a[i+1] ){
            s=i;
            break;
        }
    }

    for(int i=0;i<s;i++)cout<<a[i];

    for(int i=n-1;i>=s;i--)cout<<a[i];
    cout<<endl;
}

int32_t main(){
    int t;cin>>t;
    while(t--)solve();
    // TODO
}