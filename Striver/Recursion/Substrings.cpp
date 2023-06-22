#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void print(vector<int> v,int i,vector<int> s){
    if(i==v.size()){
        for(auto i: s)cout<<i<<' ';
        cout<<endl;
        return;
    }

    print(v,i+1,s);

    s.push_back(v[i]);
    print(v,i+1,s);
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int> s;
    print(v,0,s);


}