#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int x,y;
    cin>>x>>y;
    x=x^y; // x= x^y
    y=x^y; // y= x^y^y= x
    x=x^y; // x= x^y^x= y
    cout<<x<<' '<<y;
}