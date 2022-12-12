#include <bits/stdc++.h>
using namespace std;
int main(){
    int *p=(int*)calloc(10,sizeof(int));// the syntax is (datatype*)calloc(no.of elements, size of the element)
    for(int i=0;i<10;i++){
        cout<<*(p+i)<<" ";
    }
    free(p);
    for(int i=0;i<10;i++){
        cout<<p[i]<<" ";
    }
    //calloc works in the sameway as malloc except it initializes the values and the syntax is different
    char*l=(char*)calloc(1,sizeof(char));
    cout<<endl<<*l<<endl; // the initialization value of char is " "

}