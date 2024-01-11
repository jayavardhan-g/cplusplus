#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// Logic
// A + B = (A^B) + (A&B)<<1

int sum(int a,int b){
    return b==0?a: sum(a^b, (a&b)<<1);
}

int32_t main(){
    int a,b;cin>>a>>b;
    cout<<sum(a,b);
}