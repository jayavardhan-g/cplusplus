#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int maximumSafenessFactor(vector<vector<int>>& v){
    int n=v[0].size();
    
}
int32_t main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int> (n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>v[i][j];
    cout<<maximumSafenessFactor(v);
}