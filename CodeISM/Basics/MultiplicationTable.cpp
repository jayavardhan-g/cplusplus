#include <bits/stdc++.h>
using namespace std;
void table(int a,int b){
    if(b==0)return ;
    table(a,b-1);
    cout<<a<<"*"<<b<<"="<<a*b<<endl;
}
int main(){
    int a;cin>>a;
    table(a,10);
}