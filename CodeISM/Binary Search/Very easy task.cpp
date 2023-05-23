//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x,y;
    cin>>n>>x>>y;
    int hi=max(x*n,y*n);
    int lo=0,m,ans=hi;
    n=n-1;
    while(lo<=hi){
        m=lo+(hi-lo)/2;
        int minn=m*x + (n-m)*y;
        if(minn>ans){
            hi=m-1;
        }else{
            ans=m;
            lo=m+1;
        }
    }
}