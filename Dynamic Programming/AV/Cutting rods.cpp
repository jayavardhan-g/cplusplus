//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    int rec(int i,int j,vector<int>&v){
        if(i==v.size())return 0;
        if(j==v.size()-1)return v[j-i];

        int c,nc;
        c=v[i-j]+rec(j+1,j+1,v);
        nc= rec(i,j+1,v);

        return max(c,nc);
    }
    int cutRod(vector<int> price, int n) {
        vector<vector<int>> dp;
        return rec(0,0,price);
    }

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    cout<<cutRod(v,n);
}