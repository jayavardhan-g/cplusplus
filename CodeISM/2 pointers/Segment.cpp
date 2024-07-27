//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/I
#include<bits/stdc++.h>
using namespace std;
#define int long long
int v[100001];

bool rec(int i,int x,int n){
    if(x<0)return 0;
    if(x==0)return 1;
    if(i==n)return 0;

    bool p = rec(i+1,x-v[i],n);
    bool np = rec(i+1,x,n);

    return p|np;
}

bool sol(int l,int r,int s){
    return rec(l,s,r+1);
}

int32_t main(){
    int n,s;cin>>n>>s;
    for(int i=0;i<n;i++)cin>>v[i];

    sort(v,v+n);
    // TODO
}