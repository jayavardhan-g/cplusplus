#include <bits/stdc++.h>
using namespace std;
int main (){
    char a;
    a=10;
    char *p;
    char *q;
    char b;
    b=5;
    q=&b; //    
    p=&a;
    cout << p<< endl<< q;
    char array[3]={'a','z','L'};
    p= &array[0];
    q=&array[1];
    char *r=&array[2];
    cout << endl << endl<< p<<endl<< q<< endl<<r;


}

