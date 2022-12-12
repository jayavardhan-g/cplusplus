#include <bits/stdc++.h>
using namespace std;
void Increasing(int n){
    if(n==0) return;
    Increasing(n-1);
    cout<<n;
    return;
}
void Decreasing(int n){
    if(n==0) return;
    cout<<n;
    Decreasing(n-1);
}

int First(int a[],int n, int s, int i=0){
    
}

int main(){
    int n;
    cin>>n;
    // Increasing(n);
    // cout<<endl;
    // Decreasing(n);
    // cout<<endl;
    //first occurance and last occurance
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int s;
    cin>>s;
    cout<<First(a,n,s);


}