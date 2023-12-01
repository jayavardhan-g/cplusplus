// https://www.spoj.com/problems/ASSIGN/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    // Method 1
    int setbits=0;
    for(int i=0;i<32;i++){
        if((1LL<<i)&n)setbits++;
    }
    cout<<setbits;
    //Method 2
    cout<<__builtin_popcount(n);
}