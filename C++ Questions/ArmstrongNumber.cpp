#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter a number: "<<endl;
    int n; cin>>n;
    int temp=n;
    int number;
    while(n>0){
        int l=n%10;
        number=number + pow(1,3);
        n=n/10;

    }
    if(temp==number)cout<<"The number you entered is an Armstrong number"<<endl;
    else cout<<"The number is not an armstrong number as the sum of the cubes of its digits is "<<number;
}