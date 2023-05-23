#include<bits/stdc++.h>
using namespace std;
#define int long long

int minn(vector<int> &v,int l){
    int lo=0,hi=v.size()-1,m;
    int ans=v.size();
    while(lo<=hi){
        m=lo+(hi-lo)/2;
        if(v[m]<l)lo=m+1;
        else {
            ans=m;
            hi=m-1;
        }    
    }
    return ans;
}

int maxx(vector<int> &v,int r){
    int lo=0,hi=v.size()-1,m;
    int ans=-1;
    while(lo<=hi){
        m=lo+(hi-lo)/2;
        if(v[m]>r)hi=m-1;
        else {
            ans=m;
            lo=m+1;
        }
    }
    return ans;
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    cout<<endl;
    int k;cin>>k;
    while(k--){
        int l,r;
        cin>>l>>r;
        int s= minn(v,l);
        int e=maxx(v,r);
        cout<<(e-s+1)<<" ";

    }
}