//https://leetcode.com/problems/super-egg-drop/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int rec(int n,int k){
    if(n==0||n==1)return n;
    if(k==1)return n;

    int m = n/2;

    int r= 1+ rec(n-m,k);

    r = max(r, 1+rec(m-1,k-1) );
    return r;
}

int superEggDrop(int k, int n) {
    return rec(n,k);
}

int32_t main(){
    int n,k;cin>>k>>n;
    cout<<superEggDrop(k,n);
}