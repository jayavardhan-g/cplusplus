#include<bits/stdc++.h>
using namespace  std;
#define int long long
int32_t main(){
    int a;cin>>a;
    int m;cin>>m;
    int ans=1,fac=1;
    //find the mod of the factorial of a
    while(a!=0){
        fac*=a;
        ans=(ans%m * a%m)%m;
        a--;
    }

    cout<<"factorial is "<<fac<<" and answer is "<<ans;

}