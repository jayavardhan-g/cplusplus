#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int findNumberOfLIS(vector<int> &v)
{   
    vector<int> dp(v.size(),1),f(v.size(),1);

    int m=0;
    vector<int> ind;
    for(int i=0;i<v.size();i++){
        for (int j = 0; j < i; j++) {
            if(v[j]<v[i]){
                if(dp[i]==dp[j]+1){
                    f[i]+=f[j];
                }
                if(dp[i]<dp[j]+1){
                    f[i]=f[j];
                    dp[i]=dp[j]+1;
                }
            }
            m=max(m,dp[i]);
        }
    }
    int ans=0;
    
    // for(auto i:v)cout<<setw(4)<<i<<' ';cout<<endl;
    for(auto i:f)cout<<setw(2)<<i<<' ';cout<<endl;
    for(auto i:dp)cout<<setw(2)<<i<<' ';cout<<endl;
    cout<<m<<endl;
    for(int i=0;i<v.size();i++){
        if(dp[i]==m)ans+=f[i];
    }
    return ans;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(int  i=0;i<n;i++)cin>>v[i];
        cout<<findNumberOfLIS(v)<<endl;
    }
}