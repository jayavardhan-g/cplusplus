#include <bits/stdc++.h>
using namespace std;
int main( ){
    //3D array   
    int C[3][2][2] = {{{1,2},{3,4}},
                    {{5,6},{7,8}},
                    {{9,10},{11,12}}};
    
    int (*p)[2][2]; // pointer for a 2D array of 2 arrays of 2 elements each; int (*p)[m][n] is the pointer for a 2D array of m arrays consisting of n elements each
    p=C; p=&C[1];p=&C[2] ;  //assigning pointer to the 2D arrays which are elements of 3D array C
    
    cout<<*C<<endl; // *C= *(&C[0]) == C[0] == &C[0][0] ; &C[0][0] is the address of the 1st array of the 2D array(consisting of 2 arrays) 
    // C[i][j][k] = *(C[i][j]+k) = * (*(C[i]+j)+ k) = *(*(*(C+i)+j) +k)
    cout<< *(*(*(C+1)+1) +1)<<endl; // C[1][1][1]

}