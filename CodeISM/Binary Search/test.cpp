//https://codeforces.com/contest/1486/problem/C1?__cf_chl_tk=m7h6zxEu9nao0uVEV5E3WjCqNjLqFfaJAaVI3fm5KGw-1721489507-0.0.1.1-4052
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define print(l,r) cout<<"? "<<l<<' '<<r<<endl;

int32_t main(){
    int n;cin>>n;
    int lo=1,hi=n,m;
    
    unordered_map<string,int>mp;

    while(lo+1<hi){
        m= lo+ (hi-lo)/2;
        string s= to_string(lo)+"_"+to_string(hi);
        int sec;
        if(mp.find(s)!=mp.end()){
            sec= mp[s];
        }else{
            print(lo,hi);
            cin>>sec;
            mp[s]=sec;
        }
        int test;
        if(sec>m){
            string t= to_string(m)+"_"+to_string(hi);
            if(mp.find(t)!=mp.end()){
                test= mp[t];
            }else{
                print(m,hi);
                cin>>test;
                mp[t]=test;
            }

            if(test==sec){
                lo=m;
            }
            else{
                hi=m;
            }
        }else{
            string t= to_string(lo)+"_"+to_string(m);
            if(mp.find(t)!=mp.end()){
                test= mp[t];
            }else{
                print(lo,m);
                cin>>test;
                mp[t]=test;
            }
            if(test==sec){
                hi=m;
            }else{
                lo=m;
            }

        }
    }

    string s= to_string(lo)+"_"+to_string(hi);
    int test;
    if(mp.find(s)!=mp.end()){
        test= mp[s];
    }else{
        print(lo,hi);
        cin>>test;
    }

    if(test==lo)cout<<"! "<<hi<<endl;
    else cout<<"! "<<lo<<endl;

}
