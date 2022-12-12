#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    a=0;
    int *l;
    l=&a;
    int **m;
    m=&l;
    int ***n;
    n=&m;
    cout<< l<<"             ";
    cout<< m<<"             ";
    cout<< n<<"             ";
    cout<< endl<< *l <<"            ";
    cout<<*m<<"             ";
    cout<< *n<<"            ";
    cout<<endl<<***n;
    cout<<endl<<**m;
    cout<<endl<<*l;
    ***n+=1; // Dereferencing
    cout<<a;
    **m+=1; //Dereferencing
    cout<<a;
    *l+=1;  // Dereferencing
    cout<<a;

}