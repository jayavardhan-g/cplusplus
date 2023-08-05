#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool compare(string s,string t) {
    if(s.length()<=t.length())return 1;
    return 0;
}

bool find(string s,string t){
    if(s.length()+1!=t.length())return 0;
    
    int d=0,i=0,j=0;
    while(i<s.length() && j<t.length() && d<=1){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else{
            d++;
            j++;
        }
    }

    d+= s.length()-i + t.length()-j;
    if(d==1)return 1;
    return 0;
}

int longestStrChain(vector<string> &s)
{
    vector<int> dp(s.size(),1);

    sort(s.begin(),s.end(),compare);    

    int ans=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<i;j++){
            
            if(find(s[j],s[i])){
                dp[i]=max(dp[i],1+dp[j]);
                ans=max(ans,dp[i]);
            }
        }
    }
    // for(auto i:s)cout<<i<<' ';
    // cout<<endl;
    // for(auto i:dp)cout<<i<<' ';
    // cout<<endl;
    return ans;
}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<longestStrChain(v)<<endl;
    }
}