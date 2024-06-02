//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x,y;cin>>n>>x>>y;
    int ans=min(x,y);
    n--;
    int r=0;
    int lo=0, hi = max(x,y)*n;

    while(lo<=hi){
        int m = lo+(hi-lo)/2;

        int k = m/x + m/y;
        
        if(k>=n){
            r= m;
            hi=m-1;
        }else{
            lo = m+1;
        }
    }
    ans += r;
    cout<< ans;
}