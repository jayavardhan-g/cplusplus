#include <bits/stdc++.h>
using namespace std;
int main(){
    //after the allocation of a memory block to us the memory block will not be assigned to any other datas even if this memory block has completed its usefulness
    int* p= (int*)malloc(1000*sizeof(int));
    //if this memory block is not used it is a huge waste of memory so we need to free this space for another data which may be useful
    for(int i=0;i<30;i++){
    
        p[i]=i+1;
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
    free(p);// freeing this memory block so that it may be assigned to some other data through the malloc or calloc function
    for(int i=0;i<30;i++){
    
        
        cout<<*(p+i)<<" ";
    }
    //these bytes may still be used to dereference and storing values but the memory block is freed so if the block or a part of the block is assigned for some other purpose then we may tamper the data which is the part of the new block
    //so we should not use the bytes outside of our memory block to store values //in such cases we use realloc function
}