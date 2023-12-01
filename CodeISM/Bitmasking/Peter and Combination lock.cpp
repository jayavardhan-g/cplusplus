//https://codeforces.com/problemset/problem/1097/B
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0;i<(1LL<<(n));i++){
        // cout<<i<<' ';
        int t=0;
        for(int j=0;j<n;j++){
            if((1LL<<j)&(i))t=(t+ a[j])%360;
            else t= (t-a[j])%360;
        }
        // cout<<t<<endl;
        if(t==0){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}