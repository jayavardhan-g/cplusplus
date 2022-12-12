#include <bits/stdc++.h>
using namespace std;
void dereferencing(){
   int *p;
    int l=0, m=1;
    p=&l;
    cout<< &m<< "           "<< p<< endl<<m<<"          "<<*p<<endl ;
    *p=10;
    cout<< &m<< "           "<< p<< endl<< m<<"             "<<*p<<endl;
    p=&m;
    cout<<&m<< "            "<< p<< endl<<m<<"          "<<*p<<endl; 

};

void increment(){
    int i;
    int *p;
    p=&i;
    cout<< p;
    cout<<endl<<sizeof(int);
    cout<<endl<< p+1<<endl; // increment of a pointer increments the value of address by size of the variable -- for int it is 4
    double *l;
    double m;
    l=&m;
    cout<<l<<endl;
    cout<<sizeof(double)<<endl;
    cout<< l+1;

    

};

int main(){
    //dereferencing();
    increment();

}