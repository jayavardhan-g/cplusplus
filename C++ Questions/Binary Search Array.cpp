#include <bits/stdc++.h>
using namespace std;
int Binary(int a[],int n,int f){
    int s=0,e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==f) return mid;
        else if(a[mid]<f){s=mid+1;}
        else {e=mid-1;}
        //cout<<a[mid]<<endl;
    }
    return -1;
}
int Mine(int a[],int n,int f){
    //int mid=n/2;
    //while(a[mid]!=f){
    //    if(a[mid]>f) mid=(mid-1)/2;
    //    else mid=mid+mid/2;
    //    //cout<<a[mid]<<endl;
    //}
    //return mid;
    return 0;
}
int main(){
    int n,f;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
        //cout<<a[i];
    }
    cin>>f;
    cout<<Binary(a,n,f)<<endl;
    
}