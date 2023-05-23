#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    int lo=0,hi=n-1,m;
    int pos=-1;
    while(lo<=hi){
        m=lo+(hi-lo)/2;
        if(v[m]==0)lo=m+1;
        else{
            pos=m;
            hi=m-1;
        }
        
    }
    cout<<pos;
}