//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,t;cin>>n>>t;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];

    int l=0;
    int sum=0;
    int ans= 0;
    for(int r=0;r<n;r++){
        sum+=a[r];
        if(sum>t){
            while(sum>t){
                sum-=a[l];
                l++;
            }
        }
        ans+= r-l+1;
    }
    cout<<ans<<endl;
}