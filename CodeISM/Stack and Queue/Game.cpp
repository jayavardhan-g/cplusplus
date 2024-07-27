//https://codeforces.com/contest/1373/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;cin>>s;
    int o,z;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')o++;
        else z++;
    }

    int x =min(o,z);

    if(x%2==1){
        cout<<"DA"<<endl;
    }else{
        cout<<"NET"<<endl;
    }
}

int32_t main(){
    // FIXME
    int t;cin>>t;
    while(t--)solve();
}