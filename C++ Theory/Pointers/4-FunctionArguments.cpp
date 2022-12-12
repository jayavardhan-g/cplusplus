#include <bits/stdc++.h>
using namespace std;
void increment(int *p){
    *p=*p+1;
    
}
void increement(int **p){
    **p=**p+1;
}
int main(){
    int a=0;
    int *p=&a;
    increment(p);
    cout<<a<<endl;
    int **l;
    l=&p;
    increement(l);
    cout<<a;
}