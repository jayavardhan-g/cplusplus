#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
    int *m=&a;
    int **n=&m;
    int ***o=&n;
    int ****p=&o;
    
    cout<<"Address of m is"<<&m<<" "<<"m="<<m<<" "<<"its value is "<<*m<<endl; // value of a
    cout<<"n="<<n<<" "<<"its value is "<<*n<<endl; // address of m and address of a
    cout<<"o="<<o<<" "<<"its value is "<<*o<<endl; // address of n and address of m
    cout<<"p="<<p<<" "<<"its value is "<<*p<<endl; // address of o and address of n




}