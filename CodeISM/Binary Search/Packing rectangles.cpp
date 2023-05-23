//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
bool good(int w, int h, int n, int m) {
    return (m / w) * (m / h) >= n;
}
int32_t main(){
    int w,h,n;cin>>w>>h>>n;
    int lo=0,hi=1,m;
    while (!good(w, h, n, hi)) {
        hi *= 2;
    }
    int x=hi;
    while(lo<=hi){
        m=lo+(hi-lo)/2;
        int k=m/w;
        int l=m/h;
        int tt=k*l;
        if(n>tt){
            lo=m+1;
        }else{
            x=m;
            hi=m-1;
        }
    }
    cout<<x;
}