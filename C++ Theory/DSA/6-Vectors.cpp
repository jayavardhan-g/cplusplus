#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    //printing
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<endl;
    vector<int>::iterator i;
    for(i=v.begin();i!=v.end();i++)cout<<*i<<" ";
    cout<<endl;
    for(auto element:v)cout<<element<<" ";
    cout<<endl;

    vector<int> v1(5, -1);
    vector<int> v2(50, -50);
    for(auto i:v1)cout<<i<<' ';
    cout<<endl;
    swap(v1,v2);
    for(auto i:v1)cout<<i<<' ';
}