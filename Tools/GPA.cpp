#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    double x,y;
    double a;
    double i=0,j=0;
    while(x!=-1){
        cin>>x>>y;
        if(x==-1)break;
        x/=2;
        i+=x;
        j+=x*y;
    }
    x=0;
    while(x!=-1){
        cin>>x>>y;
        if(x==-1)break;
        i+=x;
        j+=x*y;
    }
    a=j/i;
    cout<<a;
}