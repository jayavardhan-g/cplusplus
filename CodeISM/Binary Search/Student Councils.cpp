#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool check(vector<int> &v,int x,int k){
    int left=0;
    int people=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>=x){
            people++;
        }else{
            left+=v[i];
            if(left>=x){
                people++;
                left=left%x;
            }
        }
    }
    return people>=k;
}

int32_t main(){
    int k;cin>>k;
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    int ans=0;
    int lo = 0, hi = 1e18;
    while(lo<=hi){
        int m = lo+(hi-lo)/2;

        if(check(v,m,k)){
            ans= m;
            lo = m+1;
        }else{
            hi=m-1;
        }
    }

    cout<<ans;
}