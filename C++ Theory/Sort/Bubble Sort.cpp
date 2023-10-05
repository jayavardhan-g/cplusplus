#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void bubble_sort(vector<int> &v){
    int n=v.size();
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(v[j]>v[j+1])swap(v[j],v[j+1]);
        }
    }
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    bubble_sort(v);
    for(auto i:v)cout<<i<<' ';
}