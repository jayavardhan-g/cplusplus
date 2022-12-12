#include <bits/stdc++.h>
using namespace std;
int main(){
    int *p=(int*)malloc(10*sizeof(int)); // malloc gives a void pointer hence it is important to typecast using(int*), this is for an array of 10 elements , if it is only for 1 element then 10* will be removed
    for (int i=0;i<10;i++){
        *(p+i)=i+1; // the command can be also given as p[i]=i+1;
    }
    for(int i=0;i<10;i++){
        cout<<p[i]<<" ";
    }
    free(p); // the free function may or maynot clear the values of the memory block while unallocating the memory block depending on the compiler
    cout<<endl<<"After using the free function the values the pointers are pointing to are as follows"<<endl;
    for(int i=0;i<10;i++){
        cout<<p[i]<<" ";
    }
    for (int i=0;i<10;i++){
        *(p+i)=i+1; // the command can be also given as p[i]=i+1;
    }
    cout<<endl<<"As we can see we can still dereference the pointers even after the memory block has been deallocated"<<endl; //but the memory block will be available for malloc during further processes
    for(int i=0;i<10;i++){
        cout<<p[i]<<" ";
    }
    
}