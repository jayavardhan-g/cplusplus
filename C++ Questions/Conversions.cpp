#include <bits/stdc++.h>
using namespace std;
int Bin_Dec(int a){ // binary to decimal conversion
    int e=0,num=0;
    while(a>0){
        int l=a%10;
        a=a/10;
        num=num+l*pow(2,e);
        e++;        
    }
    return num;
}
int Oct_Dec(int a){ // binary to decimal conversion
    int e=0,num=0;
    while(a>0){
        int l=a%10;
        a=a/10;
        num=num+l*pow(8,e);
        e++;        
    }
    return num;
}
int Dec_Bin (int a){
    int n=0;
    int i=0;
    while(a>0){
        int l=a%2;
        n=n+l*pow(10,i);
        a/=2;
        i++;
    }
    return n;
}
int Dec_Oct(int a){
    int n=0;
    int i=0;
    while(a>0){
        int l=a%8;
        n=n+l*pow(10,i);
        a/=8;
        i++;
    }
    return n;
}
int main(){
    int n;
    cin>>n;
    //cout<<Bin_Dec(n);
    //cout<<Oct_Dec(n);
    //cout<<Dec_Bin(n);
    cout<<Dec_Oct(n);
}