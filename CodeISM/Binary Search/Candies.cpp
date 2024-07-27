#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int n,k;

int32_t main(){
    cin>>n>>k;

    int lo=0,hi=n,m;
    int ans =0;
    while(lo<=hi){
        m = lo + (hi-lo)/2;

        int z = ((n-m)*(n-m+1))/2 - m;

        if(z==k){
            ans=m;
            break;
        }else if(z>k){
            lo = m+1;
        }else{
            hi = m-1;
        }
    }
    cout<<ans<<endl;
}