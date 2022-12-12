#include<bits/stdc++.h>
using namespace std;
void substring(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    string ros=s.substr(1);
    char c=s[0];
    substring(ros,ans);
    substring(ros,ans+c);
}
int main(){
    string s;
    cin>>s;
    substring(s,"");
}