#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    string s;cin>>s;
    int n=s.length();
    for(int i=0;i<(1<<n);i++){
        string temp="";
        for(int j=0;j<n;j++){
            if(i&(1<<j))temp+=s[j];
        }
        cout<<temp<<endl;
    }
}