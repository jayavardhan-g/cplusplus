#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    do{
        cin>>a;
        cout<<"Do-While"; //executes the loop before checking the condition -> if the condition is true then executes again
    } while (a>0);
    while(a>0){
        cin>>a;
        cout<<"While";}// executes the loop only if condition is true
}