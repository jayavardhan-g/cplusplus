#include<bits/stdc++.h>
using namespace std;
#define int long long

int pow(int n,int i){
    if(i==0)return 1;
    int ans;
    if(i%2==0){
        ans=pow(n*n,i/2);
    }
    else{
        ans=n*pow(n*n,(i-1)/2);
    }   
    return ans;
}
int pow(int n,int i,int m){
    if(i==0)return 1;
    int ans;
    if(i%2==0){
        ans=(pow((n*n)%m,i/2,m))%m;
    }
    else{
        ans=((n%m)*(pow((n*n)%m,(i-1)/2,m))%m)%m;
    }   
    return ans;
}
int iterative(int n,int i){
    int ans=1;
    while(i!=0){
        if(i%2==1){
            ans*=n;
        }
        n=n*n;
        i/=2;
    }
    return ans;
}
int iterative(int n,int i,int m){
    int ans=1;
    while(i!=0){
        if(i%2==1){
            ans=((ans%m)*(n%m))%m;
        }
        n=((n%m)*(n%m))%m;
        i/=2;
    }
    return ans;
}
int32_t main(){
    int n;cin>>n;
    int i;cin>>i;
    cout<<pow(n,i)<<endl;
    cout<<iterative(n,i)<<endl;
    cout<<iterative(n,i,2000)<<endl;
    cout<<pow(n,i,2000);
}