//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> v(n),a(k);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<k;i++)cin>>a[i];

    for(int i=0;i<k;i++){
        int x=a[i];
        int lo=0,hi=n-1,m,pos=1;

        if(v[n-1]<x){
            cout<<n+1<<endl;
            continue;
        }

        while(lo<=hi){
            m= lo + (hi-lo)/2;
            if(v[m]<x)lo=m+1;
            else{
                pos=m;
                hi=m-1;
            }
        }
        cout<<pos+1<<endl;
    }
}