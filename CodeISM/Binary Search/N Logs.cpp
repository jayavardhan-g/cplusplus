//https://atcoder.jp/contests/abc174/tasks/abc174_e
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];

    float lo =0, hi =1e10,m;

    float ans;

    while(hi-lo> 0.001){
        m = lo + (hi-lo)/2;

        int cuts= 0;
        for(int i=0;i<n;i++){
            int cut;
            cut = v[i]/m;
            if(cut*m==v[i])cut--;
            cuts+=cut;
        }

        if(cuts<=k){
            ans=m;
            hi=m-0.1;
        }else{
            lo=m+0.1;
        }

    }

    cout<<setprecision(0)<<ans<<endl;
}