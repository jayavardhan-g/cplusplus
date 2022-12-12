#include <bits/stdc++.h>
using namespace std;

void pointer(char * P){
    //cout<<sizeof (P);
    cout<<endl<<P<<endl;
}

/*void array(char A[]){
    cout<<sizeof (A[]);
    cout<<endl<<A<<endl;
}
*/
void name(char A[]){
    //cout<<sizeof (A);
    cout<<endl<<A<<endl;
}
int main() {
    char A[]="HELLO WORLD";
    pointer (A); // As the A acts as the pointer to the first element in array A
    //array (A[]);
    name (A);
    
}
