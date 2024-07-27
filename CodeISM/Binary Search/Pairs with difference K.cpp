//https://www.spoj.com/problems/HACKRNDM/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,k;
    cin>>n>>k;
    // map<int,bool> m;
    // int maxx =0;
    // for(int i=0;i<n;i++){
    //     int x;cin>>x;
    //     m[x]=1;
    //     maxx =max(maxx,x);
    // }

    // int pairs =0;
    // for(auto i:m){
    //     if(i.first>=maxx)break;
    //     if(m[i.first+k])pairs++;
    // }

    // cout<<pairs;

    int v[n];
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v, v+n);
    
    int pairs = 0;
    for(int i=0;i<n;i++){

        int lo =i, hi = n-1,m;
        while(lo<=hi){
            m= lo + (hi-lo)/2;

            if(v[m]==v[i]+k){
                pairs++;
                break;
            }else if(v[m]>v[i]+k){
                hi=m-1;
            }else{
                lo = m+1;
            }
        }

    }
    cout<<pairs;
}