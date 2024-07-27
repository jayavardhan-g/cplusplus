//https://codeforces.com/problemset/problem/1119/B
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<int> v;
int n,h;

bool check(int x){
    vector<int> t(v.begin(),v.begin()+x);
    sort(t.begin(),t.end());
    int l=0;
    for(int i = x-1;i>=0;i-=2){
        l+= t[i];
        if(l>h)return 0;
    }
    return 1;
}

int32_t main(){
    cin>>n>>h;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int lo =0, hi = n,m;
    int ans ;
    while(lo<=hi){
        m = lo + (hi-lo)/2;

        if(check(m)){
            ans = m;
            lo = m+1;
        }else{
            hi = m-1;
        }
    }
    cout<<ans<<endl;
}