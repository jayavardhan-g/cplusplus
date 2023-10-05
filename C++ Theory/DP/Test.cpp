#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int rec(int i,int s,vector<int>&v){
    if(i==v.size() && s==0)return 0;
    if(i==v.size() && s!=0)return -1e9;

    int p=1+ rec(i+1,s-v[i],v);
    int np= rec(i+1,s,v);

    return max(p,np);

}
int getLongestSubarray(vector<int>& nums, int k){
    return rec(0,k,nums);
}

int32_t main(){
        int n;cin>>n;
        int m;cin>>m;
        vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
        cout<<getLongestSubarray(v,m);
}