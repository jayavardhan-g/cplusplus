#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void selection_sort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[mini])mini=j;
        }
        swap(v[i],v[mini]);
    }
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    selection_sort(v);
    for(auto i:v)cout<<i<<' ';
}