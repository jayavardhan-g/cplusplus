#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void insertion_sort(vector<int> &v){
    int n=v.size();

    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && v[j]<v[j-1]){
            swap(v[j],v[j-1]);
            j--;
        }
    }
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    insertion_sort(v);
    for(auto i:v)cout<<i<<' ';
}