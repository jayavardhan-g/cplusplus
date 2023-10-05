#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void merge(vector<int> &v,int lo,int mid,int hi){
    int i=lo;
    int j=mid+1;
    vector<int> t;
    while(i<=mid && j<=hi){
        if(v[i]<v[j]){
            t.push_back(v[i]);
            i++;
        }else{
            t.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){t.push_back(v[i]);i++;}
    while(j<=hi){t.push_back(v[j]);j++;}

    for(auto n:t){
        v[lo]=n;
        lo++;
    }
}

void merge_sort(vector<int> &v,int lo,int hi){
    if(lo==hi)return;
    int mid= (lo+hi)/2;
    merge_sort(v,lo,mid);
    merge_sort(v,mid+1,hi);
    merge(v,lo,mid,hi);
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    merge_sort(v,0,n-1);

    for(auto i:v)cout<<i<<' ';
}