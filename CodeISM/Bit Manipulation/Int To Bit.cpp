#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;cin>>t;
    while(t--){
        int a;cin>>a;
        string x;
        for(int i=31;i>=0;i--){
            if(a&(1<<i))x+='1';
            else x+='0';
        }
        cout<<x<<endl;
    }
}