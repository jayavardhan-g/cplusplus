#include <bits/stdc++.h>
using namespace std;
string remove(string s){
    int l=s.size();
    for(int  i=0;i<s.size();i++){
        if(s[i]=='['||s[i]==']'||s[i]==',')s[i]=' ';
    }
    return s;
}
int main(){
    string s;
    cin>>s;
    s=remove(s);
    cout<<s;
}