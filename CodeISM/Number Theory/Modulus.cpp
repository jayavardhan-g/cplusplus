#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int a;cin>>a;
    int b;cin>>b;
    int m;cin>>m;
    int mod;
    // the result of the mod should be [0,m-1]
    //to do that we add m and then take the mod of the entirety
    //the following are the various operations we may do on mod
    mod= (a+b)%m;cout<<mod<<endl;
    mod= (a-b)%m;cout<<mod<<endl;
    mod= (a*b)%m;cout<<mod<<endl;
    mod= (a/b)%m;cout<<mod<<endl;
    //these may give incorrect results as these may give overflow errors
    // so these are converted to
    mod=(a%m + b%m)%m;cout<<mod<<endl;
    mod=(a%m - b%m)%m;cout<<mod<<endl;
    mod=(a%m * b%m)%m;cout<<mod<<endl;
    mod=(a%m * (1/b)%m)%m;cout<<mod<<endl;
    //when b is greater than a then we have to use this as we are applying mod on a negative number
    mod=(a%m-b%m +m)%m;cout<<mod<<endl;
    }