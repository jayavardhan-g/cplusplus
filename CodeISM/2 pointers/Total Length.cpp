//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,s;cin>>n>>s;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];

    int l=0;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++){
        sum+= a[i];
        while(sum>s){
            sum-=a[l];
            l++;
        }

        int x= i-l+1;
        ans+= (x*(x+1))/2;
    }
    cout<<ans;
}