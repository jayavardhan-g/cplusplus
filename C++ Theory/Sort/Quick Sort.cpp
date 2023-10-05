#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int pivot(vector<int> &v,int lo,int hi){
    int i=lo;
    int j=hi;
    while(i<j){
        while(i<hi && v[i]<=v[lo] )i++;
        while(j>lo && v[j]>v[lo])j--;

        if(i<j)swap(v[i],v[j]);
    }
    swap(v[lo],v[j]);
    return j;
}

void quick_sort(vector<int> &v,int lo ,int hi){
    if(lo<hi){
    int m=pivot(v,lo,hi);
    quick_sort(v,lo,m-1);
    quick_sort(v,m+1,hi);}
}

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    quick_sort(v,0,n-1);
    for(auto i:v)cout<<i<<' ';
}