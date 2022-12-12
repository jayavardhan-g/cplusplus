#include <bits/stdc++.h>
using namespace std;
int SumOfN(int n){
    if (n==0) return 0;
    int sum= SumOfN(n-1);
    return n+sum;
}
int Power(int n,int p){
    if(p==0) return 1;
    int ans=Power(n,p-1);
    return ans*n;
}
int Factorial(int n){
    if(n==0) return 1;
    int ans=Factorial(n-1);
    return ans*n;
}
int Fibonacci(int n){
    if(n==1) return 1;
    if(n==0) return 0;
    int ans = Fibonacci(n-1) + Fibonacci(n-2);
    return ans;
    
}
int main(){ 
    int n;
    cin>>n;
    cout<<SumOfN(n)<<endl;
    cout<<Power(n, 10)<<endl;
    cout<<Factorial(n)<<endl;
    cout<<Fibonacci(n)<<endl;
}