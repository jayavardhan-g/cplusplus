//https://codeforces.com/contest/279/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,t;cin>>n>>t;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];


    int l=0,r=0,sum=0;
    int ans=0;
    while(l<=r && r<n){
        if(sum <=t){
            // cout<<sum<<' '<<r<<endl;
            sum+= a[r];
            if(sum<=t)ans= max(ans, r-l+1);
            
            r++;
        }else{
            // cout<<sum<<' '<<l<<endl;
            sum-=a[l];
            l++;
        }
    }
    cout<<ans<<endl;
}