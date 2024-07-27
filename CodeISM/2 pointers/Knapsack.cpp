//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,s;cin>>n>>s;
    int w[n],c[n];
    for(int i=0;i<n;i++)cin>>w[i];
    for(int i=0;i<n;i++)cin>>c[i];

    int l=0,r=0,wt=0,ct=0;

    int ans=0;
    while(r<n){
        wt+=w[r];
        ct+=c[r];
        // cout<<r<<' '<<wt<<' '<<ct<<endl;
        while(wt>s){
            wt-=w[l];
            ct-=c[l];
            l++;
        }
        ans= max(ans,ct);
        // cout<<r<<' '<<l<<' '<<wt<<' '<<ct<<endl;
        r++;
    }
    cout<<ans;
}