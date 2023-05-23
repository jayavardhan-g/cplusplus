#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int i;
        for(i=2;i<sqrt(n);i++){
            if(n%i==0)break;
        }
        if(i==sqrt(n))cout<<"This is not a prime number";
        else cout<<"This is a prime number";
        cout<<endl;
    }
}