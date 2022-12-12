#include <bits/stdc++.h>
using namespace std;
int first(int *a,int n,int key,int i){
    int index=-1;
    if(i==n)return -1;
    if(a[i]==key)return i;
    else index=first(a,n,key,i+1);
    return index;
}
int last(int *a, int n, int key, int i){
    if(i==n)return -1;
    int index=last(a,n,key,i+1);
    if(index!=-1)return index;
    if(a[i]==key)index=i;
    return index;
}
int main(){
    int n;cin>>n;
    int a[n];
    int key;cin>>key;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<last(a,n,key,0);
}