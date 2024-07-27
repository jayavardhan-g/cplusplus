//https://codeforces.com/contest/1486/problem/C2
#include<bits/stdc++.h>
using namespace std;
#define int long long

int query(int l,int r){
    if(l>=r)return 0;
    cout<<"? "<<l<<' '<<r<<endl;
    int ans;cin>>ans;
    return ans;
}

void bsr(int lo,int hi){
    int m,r=hi;
    int sec= lo;
    while(lo+1<hi){
        int m = lo +(hi-lo)/2;
        
        int x= query(sec,m);
        if(x==sec){
            hi=m;
            r= m;
        }else{
            lo=m;
        }
    }
    if( query(sec,hi)==sec )r=hi;
    else r=lo;
    
    cout<<"! "<<r<<endl;

}

void bsl(int lo,int hi){
    int m,r=lo;
    int sec= hi;

    while(lo+1<hi){
        m = lo +(hi-lo)/2;

        int x= query(m,sec);

        if(x==sec){
            r= m;
            lo=m;
        }else{
            hi=m;
        }
    }

    if(query(lo,sec)==sec)r=lo;
    else r=hi;

    cout<<"! "<<r<<endl;
}

int32_t main(){
    int n;cin>>n;
    int sec = query(1,n);
    
    if(sec==1)bsr(1,n);
    else if(sec==n)bsl(1,n);
    else{

        if(query(1,sec)==sec)bsl(1,sec);
        else bsr(sec,n);
    }
}