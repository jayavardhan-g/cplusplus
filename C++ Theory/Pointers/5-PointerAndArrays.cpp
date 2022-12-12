#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[]={1,3,5,7,9,10,20};
    cout<<&A[0]<<endl; //p is assigned the address of first value of Array
    cout<< A<<endl; // this shows the array name is also represents the address of first element of A
    int * p=&A[0];
    cout<< p<<endl;
    p=A;           // same as p=&A[0];
    cout<<p<<endl;
    *p=20; //Dereferencing valid
    cout<< A[0];
    *A=2; //Dereferencing invalid
    cout<<endl<< A[0]<<endl;
    p++; // this gives the address of the second element of array
    cout<< p<< "    "<< *p;
    //  A++; this statement is invalid
}