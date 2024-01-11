#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int msb(int n){
    n = n| (n>>1);
    n = n| (n>>2);
    n = n| (n>>4);
    n = n| (n>>8);
    n = n| (n>>16);
    n = n| (n>>32);
    // return ((n+1)>>1); // Can overflow because of n+1
    
    return ((n+1)>>1) | (n & ( (1LL<<63) ) );
}

int32_t main(){
    int n;cin>>n;
    cout<<msb(n)<<endl;
    cout<<sizeof(n)<<endl;
    cout<< CHAR_BIT <<endl;
}