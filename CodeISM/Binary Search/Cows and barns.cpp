#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<int> v;
int n;
int c;

bool check(int d){
    int p=1;
    if(p>=c)return 1;
    int prev=v[0];
    for(int i=1;i<n;i++){
        if(v[i]-prev>=d){
            prev=v[i];
            p++;
            if(p>=c)return 1;
        }
    }
    return 0;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>c;
        v.resize(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());

        int lo=0,hi=1e6,m;
        int ans=0;
        while(lo<=hi){
            m= lo+ (hi-lo)/2;
            
            if(check(m)){
                ans=m;
                lo= m+1;
            }else{
                hi=m-1;
            }
        }
        cout<<ans<<endl;

    }
}