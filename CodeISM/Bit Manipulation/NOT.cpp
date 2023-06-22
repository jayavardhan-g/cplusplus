#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int x;
    // int m=0;
    // for(int i=0;i<32;i++){
    //     m+=(1LL<<i);
    // }
    // cout<<m<<endl;
    // string s;
    // int k=m;
    // while(k>0){
    //     if(k%2)s+='1';
    //     else s+='0';
    //     k/=2;
    // }

    // reverse(s.begin(),s.end());
    // cout<<s<<endl;
    // string s1;
    // k=n;
    // while(k>0){
    //     if(k%2)s1+='1';
    //     else s1+='0';
    //     k/=2;
    // }

    // reverse(s1.begin(),s1.end());
    // cout<<s1<<endl;
    // x=m^n;
    x=~n -1;
    cout<<x;
}