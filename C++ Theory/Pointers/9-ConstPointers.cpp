#include <bits/stdc++.h>
using namespace std;

void print( const char *A){
    // A[3]='J';
    cout<<A;
}

int main(){
    char A[]="Hello";
    const char*L;
    L=&A[0];
    print(L);

    // when added the const prefix to the pointer the values of the array can not be changed in the function
}
