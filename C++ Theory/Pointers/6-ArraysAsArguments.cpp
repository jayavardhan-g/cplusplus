#include <bits/stdc++.h>
using namespace std;
void FinA(int a[],int m){
    int sum=0;
    int size=m;
    for (int i=0;i<size;i++){sum+=a[i];}
    cout<<sum<<endl;

}
int main(){
    int A[]={1,3,5,7,9,10,20,0};
    int size=sizeof(A)/sizeof(A[0]);
    int sum=0;
    for (int i=0;i<size;i++){   
        sum+=A[i];
    }
    do {sum=0;}while(sum>0);
    cout<<sizeof(A)<<"      "<<sizeof(A[0])<<"      "<< size<<endl<< sum<<endl;
    FinA(A, size) ;
}