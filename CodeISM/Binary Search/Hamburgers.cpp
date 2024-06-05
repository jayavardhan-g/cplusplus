#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int nb,ns,nc;
int pb,ps,pc;
int r;
int hb=0,hs=0,hc=0;

int check(int x){
    int tb = x*hb;
    int ts = x*hs;
    int tc = x*hc;

    int lb= tb-nb<0? 0 : tb-nb;
    int ls= ts-ns<0? 0 : ts-ns;
    int lc= tc-nc<0? 0 : tc-nc;

    int cost = lb*pb + ls*ps + lc*pc;
    
    return cost<=r;

}

int32_t main(){
    string s;cin>>s;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>r;
    for(int i=0;i<s.length();i++){
        if(s[i]=='B')hb++;
        if(s[i]=='S')hs++;
        if(s[i]=='C')hc++;
    }

    int ans=0;
    int lo=0,hi=1e15;
    while(lo<=hi){
        int m=lo + (hi-lo)/2;

        if(check(m)){
            ans = m;
            lo = m+1;
        }else{
            hi = m-1;
        }
    }
    cout<<ans;
}