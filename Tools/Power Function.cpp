#include <bits/stdc++.h>
#define int long long
using namespace std;
int pow(int n,int i){
    if(i==0)return 1;
    return n*pow(n,i-1);
}
int32_t main(){
    int n;cin>>n;
    int i;cin>>i;
    cout<<pow(n,i);
}