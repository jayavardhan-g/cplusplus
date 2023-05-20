#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int x;cin>>x;
    int lo=0,hi=n-1,m;
    while(lo <= hi){
        m=(hi+lo)/2;
        if(x==v[m]){cout<<m<<endl;break;}
        if(x>v[m]){
            lo=m+1;
        }
        else{
            hi=m-1;
        }
    }

}