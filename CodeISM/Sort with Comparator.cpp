#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> &x,pair <int,int> y){
    return x.second<=y.second;
}

int main(){
    vector<pair<int,int>> v;
    int n;cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)cout<<v[i].first<<' '<<v[i].second<<endl;
}