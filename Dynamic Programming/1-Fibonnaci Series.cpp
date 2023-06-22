#include<bits/stdc++.h>
using namespace std;
#define int long long

int fib(int n,vector<int> &v){
    if(v[n]!=-1)return v[n];
    else{
        v[n]=fib(n-1,v)+fib(n-2,v);
        return v[n];
    }
}

int32_t main(){
    vector<int> v(1001,-1);
    v[0]=0;
    v[1]=1;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<fib(n,v);
    }
    
}