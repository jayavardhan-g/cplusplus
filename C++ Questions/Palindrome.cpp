#include <bits/stdc++.h>
using namespace std;
int main(){
    char c[100];
    cin>>c;
    cout<<c;
    int n=0;
    while(c[n]!='\0'){
        n++;
    }
    int i=0;
    for(i;i<n/2;i++){
        if(c[i]!=c[n-1-i]){cout<<"This is not a palindrome";break;}
    }
    if(i==n/2) cout<<"This is a palindrome";
    
}