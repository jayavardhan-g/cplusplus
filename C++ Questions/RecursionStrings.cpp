#include<bits/stdc++.h>
using namespace std;
void movex(string &s){
    if(s.length()==0)return;
    if(s[0]=='x'){
        string ros=s.substr(1);
        movex(ros);
        s=ros+'x';
    }
    else{
        string ros=s.substr(1);
        movex(ros);
        s=s[0]+ros;
    }
}
int main(){
    string s;
    cin>>s;
    movex(s);
    cout<<s;
}