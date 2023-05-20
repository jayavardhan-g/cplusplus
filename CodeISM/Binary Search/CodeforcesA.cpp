#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<int>v(n);
    int k;cin>>k;
    vector<int>a(k);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<k;i++)cin>>a[i];

    for(int i=0;i<k;i++){
        int x=a[i];
        int lo=0,hi=n-1,m;
        int pos=-1;
        while(lo<=hi){
            m=lo+(hi-lo)/2;
            if(v[m]==x){
                pos=m;break;
            }
            else if(v[m]>x){
                hi=m-1;
            }
            else lo=m+1;
        }
        if(pos==-1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}