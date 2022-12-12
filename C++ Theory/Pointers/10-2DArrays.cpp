#include <bits/stdc++.h>
using namespace std;
int main(){
    int B[2][3]={{1,2,3},{4,5,6}} ;//defining a 2 dimensional array(array of arrays) in this case array of 2 arrays of 3 elements each
    int *l; //pointer
    int (*p)[3]; // pointer to an array consisting of 3 elements datatype (*p)[n] for an array consisting of n elements
    l= *(B); // here B= pointer to the first element of B i.e B[0] so *(B)= B[0] , B[0] is the pointer to the first element in B[0] i.e B[0][0]
    p= B; // B = pointer to the first element of B i.e B[0] which is an array of 3 elements -> p is the pointer to an array of 3 elements i.e B[0]
    cout<< l<<endl<<p<<endl;
    // problems
    cout<< *B + 1<<endl; // *B= B[0] ; B[0]+1 = &B[0][0] + 1 = &B[0][1] 
    cout<< B+1<<endl; // B= &B[0] +1 = &B[1];
    cout<< *(*B+1)<<endl; // *B= *(&B[0]) = B[0]= &B[0][0] ; *B+1 = &B[0][0] +1 = &B[0][1] ; *(&B[0][1])

    // B[i][j] == *(B[i]+j) == *(*(B +i)+j) 
    cout<< *(*(B+1)+2);

}