#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p[n]={0};
    for(int i=2;i<=n;i++){
        if(p[i]==0){
            p[i]=i;
            
            for(int j=i*i;j<=n;j+=i) p[j]=p[j]>0?p[j]:i;
        }
    }
    
    while(n!=1){
        cout<<p[n]<<" ";
        n=n/p[n];
    }
}