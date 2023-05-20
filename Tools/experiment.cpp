#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    double f,p,a,v; 
    f=50;p=1;
    while(p!=0){
        cin>>p;
        p/=1000;
        a=(1-f*p)*180;
        
        cout<<"p = "<<p<<endl;
        cout<<"f*p= "<<f*p<<endl;
        cout<<"a = "<<a<<endl;
        cout<<"--------------"<<endl<<endl;
    }
}