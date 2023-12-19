#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void ntobi(int n){
    while(n>0){
        cout<<n%2;
        n/=2;
    }
    cout<<endl;
}

int32_t main(){
    int a,b;cin>>a>>b;
    int x = a^b;
    x = (b<<1)^x;
    ntobi(a);
    ntobi(b);
    ntobi(x);
    ntobi(a+b);
    cout<<x;
}