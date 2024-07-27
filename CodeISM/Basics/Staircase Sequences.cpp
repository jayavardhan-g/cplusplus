//https://atcoder.jp/contests/abc190/tasks/abc190_d
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int x;cin>>x;
    int ans=0;
    int m= 2*x;
    for(int i=1;i*i<=m;i++){
        if(m%i == 0){
            int k1= i,k2= m/i;

            if( (m/k1 + 1- k1)%2==0 )ans++;

            if( k1!=k2 && (m/k2 +1 -k2)%2==0 )ans++;
        }
    }
    cout<<ans<<endl;
}