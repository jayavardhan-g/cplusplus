//https://www.spoj.com/problems/EKO/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int ans=0;
    int sum=0;
    int x=0;
    for(int i=n-1;i>0;i--){
        sum+=v[i];
        x++;
        int lo=v[i-1],hi=v[i],m;
        while(lo<=hi){
            m=lo+(hi-lo)/2;
            if((sum-m*x)>=k){
                ans=m;
                lo=m+1;
            }
            else hi=m-1;
        }
        if(ans!=0)break;
    }
    cout<<endl<<ans;
}