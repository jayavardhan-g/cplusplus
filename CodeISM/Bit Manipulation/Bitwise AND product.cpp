//https://www.hackerrank.com/challenges/and-product/problem

#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b; // 10001 10111
        if(a==b){
            cout<<a;
            continue;
        }
        int ans=0;
        for(int i=32;i>0;i--){
            if((a&(1LL<<i)) == (b&(1LL<<i)))ans+=(a&(1LL<<i));
        }
        cout<<ans<<endl;
    }

}
// Solution
/*
We see upto which bit both the numbers have equal bits
eg. if a = 110101001
       b = 110101101
       They are both same upto 110101 so that is the AND product and others will be gone as there will be atleast 
       one 0 in it
       
*/