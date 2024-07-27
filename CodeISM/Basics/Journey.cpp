//https://docs.google.com/document/d/1EY-Ds5mu3IM8lrJPRZZ-L7tvjucgyp9O7VmzPbH5kco/edit
#include<bits/stdc++.h>
using namespace std;
#define int long long

int sol(vector<pair<int,int>> &v,int i,int z,int n){

    int lo=i, hi=n-1,m,r;
    while(lo<=hi){
        m=lo + (hi-lo)/2;

        if( v[m].first - v[i].first <=m  ){
            r= m;
            lo=m+1;
        }else{
            hi=m-1;
        }
    }
    int x =v[i].second + v[r].second + v[r].first - v[i].first; 
    return x;
}

int32_t main(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)cin>>v[i].second>>v[i].first;

    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans= max(ans, sol(v,i,m,n) );
    }
    cout<<ans<<endl;
}