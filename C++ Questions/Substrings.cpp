#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    unsigned long long int ans=1;
    int l=1000000007;
    while(n>0){
        ans=(ans*n)%l;
        n--;
    }
    return ans;
}
unsigned long long factorial2(int n)
{
    const unsigned int M = 1000000007;
 
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f*i) % M;  // Now f never can
                        // exceed 10^9+7
    return f;
}
int main(){
    int n;cin>>n;
    cout<<factorial(n)<<endl;
    cout<<factorial2(n);
}