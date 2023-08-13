#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


int32_t main(){
    int n;cin>>n;
    set<int> s;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    for(auto i=s.begin();i!=s.end();i++)cout<<*i;
    cout<<endl;

    auto i=s.begin();
    for(int a=0;a<3;a++)i++;
    cout<<*i;
    i--;
    cout<<*i;
}