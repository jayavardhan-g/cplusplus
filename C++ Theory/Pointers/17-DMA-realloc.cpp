#include <bits/stdc++.h>
using namespace std;
int main(){
    int *p=(int*)calloc(5,sizeof(int));
    for (int i=0;i<10;i++){
        *(p+1)=i+1;
        cout<<*(p+1);
    }
    *(p+100)=100;
    //we can assign values to the pointers continuing the memory block even without increasing the size of the memory block
    //but the remaining part of the memory block where we stored the values is still available for malloc so that malloc can assign it to another array or data
    cout<<endl<<p[100];
    //the address which is pointed by the pointer may be the data of another block so we should only change the values in the memory block allocated to us
    // this is possible by using realloc to increase the size of the memory block without tampering anyother data and copying the original values to other newly created block if possible
    char *c=(char*)(p+100);
    cout<<*c; //in this case the address at 400bytes from p is assigned to a character (this is forcefully coincided) but there may be cases 
              //when many data types may actually coincide because we are not working in our assigned memory blocks
    int* l=(int*)realloc(p,100*sizeof(int)); // (datatype*)realloc(arraytoincrease, sizeof array *sizeof one element in array)
    //now this memory block will not be allocated to any other data through malloc to tamper with our data

    int *m=(int *)malloc(10*sizeof(int));
    int *L=(int*)realloc(m,0); // when the byte size is 0 we are actually freeing the block of memory for m;
    int *G=(int *)realloc(NULL,20*sizeof(int)); // when the array argument is NULL in realloc and size is given the realloc actually works as malloc
}