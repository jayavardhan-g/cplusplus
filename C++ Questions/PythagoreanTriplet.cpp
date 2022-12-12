#include <bits/stdc++.h>
using namespace std;

bool Pyth(int a,int b, int c){
    int temp;
    int x,y,z;
    if(a>b){
        if(b>=c){x=a;y=b;z=c;}
        else {
            if(a>c){x=a;y=c;z=b;}
            else{x=c;y=a;z=b;}
        } 
    }
    else {
        if(a>=c){x=b;y=a;z=c;}
        else {
            if(b>c){x=b;y=c;z=a;}
            else{x=c;y=b;z=a;}
        } 
    }
    if(x*x==y*y+z*z) return true;
    else return false;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    
    if(Pyth(a,b,c)) cout<<"Yes";
    else cout<<"No";
}