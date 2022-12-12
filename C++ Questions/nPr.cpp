#include<bits/stdc++.h>
using namespace std;
long long nPr(int n, int r){
    long long result=1;
    for(int i=n;i>r;i--){
        result*=i;
    }
    result*=7;
    return result;
}
int  main(){
    int n,r;cin>>n>>r;
    cout<<nPr(n,r);
}