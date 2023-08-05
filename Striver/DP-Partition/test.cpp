#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> rec(int lo,int hi, string &s){
    if(lo==hi){
        pair<int,int>p;
        if(s[lo]=='F'){
            p.first=1;p.second=0;
        }else{
            p.first=0;p.second=1;
        }
        return p;
    }
    int ans=0;
    pair<int,int> p;
    p.first=0;
    p.second=0;

    for(int i=lo+1;i<hi;i+=2){
        int x0,x1,y0,y1;
        x0=rec(lo,i-1,s).first;
        x1=rec(lo,i-1,s).second;
        y0=rec(i+1,hi,s).first;
        y1=rec(i+1,hi,s).second;
        if(s[i]=='&'){
            p.first+= x0*y1 + y0*x1 + x0*y0;
            p.second+= x1*y1;
        }else if(s[i]=='|'){
            p.first+=x0*y0;
            p.second+= x1*y1 + x0*y1 + x1*y0;
        }else{
            p.first+=x0*y0 + x1*y1;
            p.second+= x1*y0 + x0*y1;
        }
    }
    return p;
    
}
int countWays(int N, string S){
    return rec(0,S.length()-1,S).second;
}

int32_t main(){
    string s;cin>>s;
    cin>>s;
    cout<<countWays(0,s);
}