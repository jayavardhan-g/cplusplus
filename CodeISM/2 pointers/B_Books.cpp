//https://codeforces.com/contest/279/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int t;cin>>t;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    int i=0,j=0;
    int x=0;
    int sum=v[i]; 
    while(j<n && i<n){
       if(sum<=t){
        x=max(x, (j-i)+1);
        j++;
        sum+=v[j];
       }else{
        sum-=v[i];
        i++;
       }
    }
    cout<<x;
}