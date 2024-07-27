//https://codeforces.com/contest/1486/problem/C1?__cf_chl_tk=m7h6zxEu9nao0uVEV5E3WjCqNjLqFfaJAaVI3fm5KGw-1721489507-0.0.1.1-4052
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define print(l,r) cout<<"? "<<l<<' '<<r<<endl;

int32_t main(){
    int n;cin>>n;
    int lo=1,hi=n,m;
    
    
    while(lo+1<hi){
        print(lo,hi);
        int sec;cin>>sec;
        m= lo+(hi-lo)/2;
        
        if(sec<=m){
            print(lo,m);
            int test;cin>>test;
            if(test==sec){
                hi=m;
            }else{
                lo=m;
            }
        }else{
            print(m,hi);
            int test;cin>>test;
            if(test==sec){
                lo=m;
            }else{
                hi=m;
            }
        }
    }

    print(lo,hi);
    int test;cin>>test;

    if(test==lo)cout<<"! "<<hi<<endl;
    else cout<<"! "<<lo<<endl;
}