//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int i=0,sum=0;
    int ans=INT_MAX;
    for (int j = 0; j < n; j++)
    {
        sum+=v[j];
        while(sum-v[i]>=k){
            sum-=v[i];
            i++;
        }
        if(sum>=k)ans=min(ans,j-i+1);
    }
    ans= (ans==INT_MAX)?-1:ans;
    cout<<ans;
}