#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    int reverse=0;
    while(n!=0){
        int l=n%10;
        reverse=reverse*10+l;
        n=n/10;
    }
    cout<<reverse;
}