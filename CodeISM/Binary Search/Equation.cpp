//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    double c;cin>>c;
    // double d= 0.00000001;
    double lo =0,hi= sqrt(c)+1;
    while(lo<=hi){
        double m = lo+ (hi-lo)/2;

        double z = sqrt(m) + m*m;

        if(abs(z-c)< 0.000001){
            cout<<setprecision(16)<<m;
            return 0;
        }else if(z>c){
            hi=m;
        }else{
            lo=m;
        }
    }

    // double c;cin>>c;
 
    // double lo =1,hi= sqrt(c)+1;
    // while(lo<=hi){
    //     double m = lo+ (hi-lo)/2;
 
    //     double z = sqrt(m) + m*m;
 
    //     if( abs(z-c)<0.000001 ){
    //         cout<<setprecision(716)<<m;
    //         return 0;
    //     }else if(z>c){
    //         hi=m-0.00000001;
    //     }else{
    //         lo=m+0.00000001;
    //     }
    // }
}