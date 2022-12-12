#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    set<int> st;
    
    // Adding elements
    st.insert(1);
    st.insert(2);
    st.insert(9);
    st.insert(5);
    st.insert(6);
    st.insert(3);
    st.insert(4);
    st.insert(4);
    // Printing
    for(auto it=st.begin();it!=st.end();it++)cout<<*it<<' ';
    // Finding elements
    auto it=st.find(6);
    cout<<*it;
    if(it==st.end())cout<<"FALSE"<<endl;
    else cout<<"TRUE"<<endl;
    st.erase(6);
    for(auto it=st.begin();it!=st.end();it++)cout<<*it<<' ';
    it=st.find(6);
    if(it==st.end())cout<<"FALSE"<<endl;
    else cout<<"TRUE"<<endl;

    it=st.find(10);
    if(it==st.end())cout<<"FALSE"<<endl;
    cout<<*it;
}