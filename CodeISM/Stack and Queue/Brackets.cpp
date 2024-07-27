//https://www.hackerrank.com/challenges/balanced-brackets/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==']' && !st.empty() && st.top()=='[')st.pop();
            else if(s[i]=='}' && !st.empty() && st.top()=='{')st.pop();
            else if(s[i]==')' && !st.empty() && st.top()=='(')st.pop();
            else {st.push('[');break;}
        }
        if(!st.empty())cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}