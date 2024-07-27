//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,k;cin>>n>>k;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];

    int ans=0;
    unordered_map<int,int> mp;
    int z=0,l=0;
    for(int r=0;r<n;r++){
        
        mp[a[r]]++;
        if(mp[a[r]]==1)z++;

        while(z>k){
            mp[a[l]]--;
            if(mp[a[l]]==0)z--;
            l++;
        }
        
        ans+= r-l+1;
    }
    cout<<ans<<endl;
}