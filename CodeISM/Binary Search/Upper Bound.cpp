#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    while(k--){
        int lo=0,hi=n-1,m,pos=0;
        int t;cin>>t;
        while(lo<=hi){
            m=lo+(hi-lo)/2;
            if(v[m]<=t){
                pos=m+1;
                lo=m+1;
            }else{
                hi=m-1;
            }
        }
        cout<<pos<<endl;
    }
}