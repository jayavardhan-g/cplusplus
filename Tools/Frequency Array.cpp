#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> f(10001,0);
    vector<int> v;
    int x=0;
    int max=0;
    while(x!=-1){
        cin>>x;
        v.push_back(x);
        f[v[v.size()-1]]+=v[v.size()-1];
        if(x>max)max=x;
    }

    for(int i=0;i<max+1;i++){
        cout<<i<<"->"<<f[i]<<endl;
    }
}