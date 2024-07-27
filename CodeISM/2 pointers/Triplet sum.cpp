//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool find3Numbers(int a[], int n, int x){   
    sort(&a[0],&a[n]);
    bool flag=0;
    for(int i=0;i<n;i++){
        int sumleft= x- a[i];
        int l=i+1,r= n-1;
        while(l<r){
            if(a[l]+a[r]==sumleft){return 1;}
            if(a[l]+a[r]>sumleft){
                r--;
            }else{
                l++;
            }
        }   
    }
    return 0;
}
int32_t main(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    int x;cin>>x;
    cout<<find3Numbers(a,n,x);
}