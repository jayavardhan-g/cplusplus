//https://codeforces.com/problemset/problem/582/A
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;cin>>n;
    
    map<int,int,greater<int>> mp;
    for(int i=0;i<n*n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    vector<int> ans;
    for(auto i= mp.begin();i!=mp.end();){
        if( i->second >0 ){
            ans.push_back(i->first);

            for(auto j:ans){
                mp[__gcd(j,i->first)]-=2;
            }
        }

        if(i->second<=0)i++;
    }

    for(auto i:ans)cout<<i<<' ';
}