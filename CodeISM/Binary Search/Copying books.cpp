//https://www.spoj.com/problems/BOOKS1/
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
bool check(int v[],int n,int m,int w,int s){
    int sum=0;
    int z=0;
    
    for(int i=s;i<n;i++){
        if(v[i]+sum>m){
            if(sum==0)return 0;
            sum=v[i];
            z++;
        }else{
            sum+=v[i];
        }
    }
 
    if(z < w)return 1;
    return 0;
 
}
 
void solve(){
    int n,w;cin>>n>>w;
    int v[n];for(int i=0;i<n;i++)cin>>v[i];
 
    int lo=0,hi=1e9,m,r;
    while(lo<=hi){
        m = lo + (hi-lo)/2;
        
        if(check(v,n,m,w,0)){
            r=m;
            hi=m-1;
        }else{
            lo = m+1;
        }
 
    }
    // cout<<r<<endl;
 
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
        if(check(v,n,r,w-1,i+1)){
            cout<<"/ ";
            w--;
        }
    }
    cout<<endl;
 
}
 
int32_t main(){
    int t;cin>>t;
    while(t--)solve();
} 
// SOLVED