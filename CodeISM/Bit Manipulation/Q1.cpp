//You are given an array of integers in which each number is repeated twice except one number, Find that number

#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<int> v;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    x=0;
    for(int i=0;i<n;i++)x^=v[i];
    cout<<x;
}