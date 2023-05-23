#include<bits/stdc++.h>
#define int long long
using namespace std;
int GCD(int a,int b){
    if(b==0)return a;
    return GCD(b,a%b);
}   
int32_t main(){
    int a,b;cin>>a>>b;
    cout<<GCD(a,b);
}