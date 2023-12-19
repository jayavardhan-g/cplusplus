#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    set<pair<int,int>> s;
    s.insert({0,1});
    s.insert({1,2});
    s.insert({2,3});
    auto x=s.end();
    x--;
    cout<<x->first<<endl;

}