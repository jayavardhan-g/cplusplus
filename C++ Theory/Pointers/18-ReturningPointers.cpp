#include <bits/stdc++.h>
using namespace std;
int* plusss(int*a ,int *b){
    cout<<"The addresses of a and b in plusss are: "<<&a<<" "<<&b<<endl;
    cout<<"The values of a and b in main are: "<<a<<" "<<b<<endl;
    int *s=(int *)malloc(sizeof(int));//we can not return an address of the variable which is local to a function because when the function finishes the memory is cleared or allocated to another function which may change our data
    *s=*a+*b; // we have to use malloc to assign the value in heap memory so that it is not cleared until the application finishes
    return s;
}
int main(){
    int a=20,b=10;
    int *l=&a,*m=&b;
    cout<<"The addresses of a and b in main are : "<<l<<" "<<m<<endl;
    cout<<"The values of a and b in main are: "<<a<<" "<<b<<endl;
    int *s=plusss(l,m); // this is call by reference (in order to not copy large datas like arrays)
    cout<<*s;
}