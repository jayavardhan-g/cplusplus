//Check whether a number is even or odd without using % operator

#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    // double x=178, y= 7.8;
    // double z=49,l;
    // cin>>l;
    // double gpa=(x*y+z*l)/(x+z);
    // cout<<gpa;

    double x=0,gpa=0;
    while(x!=-1){
        gpa+=x;
        cin>>x;
    }
    cout<<gpa/5;
}