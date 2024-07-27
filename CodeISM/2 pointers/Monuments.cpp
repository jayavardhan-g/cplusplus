//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,d;cin>>n>>d;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];

    int l=0,ans=0;
    for(int r=1;r<n;r++){
        while(l<n && a[r]-a[l]>d){
            l++;
        }

        ans+=l;
    }
    cout<<ans;
}