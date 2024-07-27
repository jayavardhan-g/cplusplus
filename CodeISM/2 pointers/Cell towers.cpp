//https://codeforces.com/problemset/problem/702/C
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,m;cin>>n>>m;
    

    int c[n];for(int i=0;i<n;i++)cin>>c[i];
    int t[m];for(int i=0;i<m;i++)cin>>t[i];

    int i=0,j=0;

    int r=0;
    for(i;i<n;i++){
        // cout<<i<<' ';
        while( j<m-1 && abs(c[i]-t[j+1])<=abs(c[i]-t[j]) ){
            j++;
        }
        // cout<<j<<endl;
        int z= abs(c[i]-t[j]);
        // cout<<z<<endl;
        if(j<m-1)z= min(z, abs(c[i]-t[j+1]));

        r= max(z,r);
    }
    cout<<r<<endl;
}