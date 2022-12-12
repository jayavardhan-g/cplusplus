#include <bits/stdc++.h>
using namespace std;
int sum(int a){
    if(a==0)return 0;
    int s=a%10;
    a=a/10;
    s+=sum(a);
    return s;
}
int main(){
    int i;cin>>i;
    cout<<sum(i);
    
}