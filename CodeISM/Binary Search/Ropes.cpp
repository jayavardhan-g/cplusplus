//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<double> v(n);
    double hi=1e9;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    double lo=0,m,ans;
    while(lo<=hi){
        m=lo+(hi-lo)/2;
        int x=0;
        for(int i=0;i<n;i++){
            x+=v[i]/m;
        }
        if(x>=k){
            lo=m+0.00000001;
        }
        else{
            ans=m;
            hi=m-0.00000001;
        }
    }
    cout<<setprecision(20)<<ans;
}