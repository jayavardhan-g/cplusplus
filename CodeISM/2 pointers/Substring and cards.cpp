//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    string t;cin>>t;

    vector<int> st(26,0),cd(26,0);
    for(int i=0;i<m;i++){
        cd[t[i]-'a']++;
    }
    // for(auto i:st)cout<<i<<' ';
    int l=0,r=0,ans=0;

    while(r<n){
        st[s[r]-'a']++;

        while(st[s[r]-'a']>cd[s[r]-'a']){
            st[s[l]-'a']--;
            l++;
        }

        ans+=r-l+1;
        r++;
    }
    cout<<ans<<endl;
}