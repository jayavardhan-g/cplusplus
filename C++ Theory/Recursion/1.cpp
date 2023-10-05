#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void sol(vector<int> v,vector<int> &s,int i,int ans){
    if(i==v.size()){s.push_back(ans);return;}
    sol(v,s,i+1,ans);
    sol(v,s,i+1,ans+v[i]);
}


int32_t main(){
    int n;cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++)cin>>num[i];
    vector<int> s;
    sol(num,s,0,0);
    for(auto i:s)cout<<i<<' ';
}