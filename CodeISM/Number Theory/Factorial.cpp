#include<bits/stdc++.h>
using namespace std;
int factorial(int a){
    if(a==0)return 1;
    a=a*factorial(a-1);
    return a;
} 
int main(){
    int a;cin>>a;
    cout<<factorial(a);
}