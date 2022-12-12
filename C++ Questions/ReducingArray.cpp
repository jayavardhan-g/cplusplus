#include<bits/stdc++.h>
using namespace std;
bool firstcompare(pair <int,int>p1, pair<int,int>p2){
    return p1.first<p2.first;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    int r[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        pair <int,int> p;
        p.first=a[i];
        p.second=i;
        v.push_back(p);
        //v.push_back(make_pair(a[i],i));
    }
    for(int i=0;i<n;i++)cout<<" "<<a[i];
    cout<<endl;
    //sort the vector based on the first element
    sort(v.begin(),v.end(),firstcompare);
    for(int i=0;i<v.size();i++){
        a[v[i].second]=i;
    }
    
    
    for(int i=0;i<n;i++)cout<<" "<<a[i];

}