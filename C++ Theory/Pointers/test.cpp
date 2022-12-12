#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int i=0;
    for(i=2;i<=n;i++){
        if(n%i==0)cout<<"I is not prime";
    }
    if(i==n) cout<<"i is prime";
    
}