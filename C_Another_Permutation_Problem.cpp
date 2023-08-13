#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

pair<int,int> rec(int i,int n,int M,vector<bool> &s){
    return {0,0};
}

int32_t main(){
    int n;cin>>n;
    vector<bool> s(n+1,0);
    cout<< rec(1,n,0,s).first - rec(1,n,0,s).second;
    int ans=0;

    for(int i=1;i<=5;i++){
        ans+= i*(10-i+1);
    }
    ans-= 20;
    cout<<ans;
}