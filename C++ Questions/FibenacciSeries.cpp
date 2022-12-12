#include <bits/stdc++.h>
using namespace std;
void Fib(int n){
    int t1=0,t2=1,t3; 
    cout<<t1<<","<<t2<<",";
    for(int i=0;i<n;i++){ 
        t3=t1+t2;
        cout<<t3<<",";
        t3=t1+t2;
        t1=t2;
        t2=t3;
    }

}

int main(){
    int n;
    cin>>n;
    Fib(n);
}