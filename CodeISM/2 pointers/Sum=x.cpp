//https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>
using namespace std;
// #define int long long

int32_t main(){
    int n,t;cin>>n>>t;

    pair<int,int> a[n];

    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }

    sort(a,a+n);

    int l=0,r=n-1;
    
    int sum = 0;
    
    while(l<r){
        if(a[l].first+a[r].first > t){
            r--;
        }else if(a[l].first+a[r].first<t){
            l++;
        }else{
            cout<<a[l].second+1<<' '<<a[r].second+1;
            return 0;
        }
    }

    cout<<"IMPOSSIBLE";

}