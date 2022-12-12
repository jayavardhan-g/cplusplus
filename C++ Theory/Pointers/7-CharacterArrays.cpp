#include <bits/stdc++.h>
using namespace std;
int main(){

    char name[]= "JAY JAY";
    cout<< name<< endl;
    cout<< strlen(name)<< endl;
    cout<< sizeof(name);
    char *n;
    
    n=name; // the pointer n is given the value of address of the first element of array name
    cout<<endl<< n[4];
    cout<< endl<< *(n+4); 
    // both the above mentioned lines are the same i.e n[4]= * (n+4)
    n++;

    cout<<endl<<n;
    n++;
    cout<< endl<< n;
    // n=name possible but
    // name=n not possible 
    // n++ can be done not name++
}