#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> divisibleSet(vector<int> &v) {
    sort(v.begin(), v.end());

    vector<int> dp(v.size(),1);
    vector<int> f(v.size());

    int ans=0,ind=0;

    for(int i=0;i<v.size();i++)f[i]=i;
    for (int i = 0; i < v.size(); i++){
        for(int j=0;j<i;j++){
            if(v[i]%v[j]==0){
                dp[i]=max(dp[i], 1+dp[j]);
                if(dp[i]==1+dp[j])f[i]=j;

                if(dp[i]>ans){
                    ind=i;
                    ans=dp[i];
                }
            }
        }
    }
    // cout<<ind<<endl;
    vector<int> a;
    while(f[ind]!=ind){
        a.push_back(v[ind]);
        ind=f[ind];
    }
    a.push_back(v[ind]);
    // for(auto i:v)cout<<i<<' ';
    // cout<<endl;
    // for(auto i:dp)cout<<i<<' ';
    // cout<<endl;
    // for(auto i:f)cout<<i<<' ';
    // cout<<endl;
    // sort(a.begin(),a.end());
    return a;

}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        v=divisibleSet(v);
        for(auto i:v)cout<<i<<' ';
        cout<<endl;
    }
}