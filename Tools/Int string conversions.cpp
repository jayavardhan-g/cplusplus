#include<bits/stdc++.h>
using namespace std;
#define int long long
string inttoa(int a){
    int n=0;
    int x=a;
    string s;
    char l;
    while(x>0){
        a=x%10;
        x/=10;
        l=a+'0';
        s.push_back(l);
    }
    for(int i=0;i<s.size()/2;i++){
        l=s[i];
        s[i]=s[s.size()-1-i];
        s[s.size()-i-1]=l;     
    }
    return s;
}
int strtoint(string s){
    vector<int> v;
    int x=1;
    for(int i=0;i<s.size();i++){
        v.push_back(s[i]-48);
        if(i>0)x*=10;
    }
    cout<<x<<endl;
    int a=0;
    for(int i=0;i<v.size();i++){
        a+= x*v[i];
        x/=10;
    }
    return a;
}
int32_t main(){
    string s=inttoa(3534);
    s[2]='0';
    cout<<s<<endl;
    int l=strtoint(s);
    cout<<l;
    l+=33;
    cout<<endl<<l;
}