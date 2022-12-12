#include<bits/stdc++.h>
using namespace std;
int sum(vector<int>v, int k, int s, int l){
    if(v.size()=0)return s;
    if(l==0){s+=v[v.size()-1]&k; v.pop_back(); k--;}
    for(int i=0;i<k;i++){
        int j;
        if(i<v.size())j=sum(v, k,s,1);
        else j=sum(v,k,s,0);
    }

}
int main(){
    int n,k,m;
    cin>>n;
    vector <int> v;
    for(int i=0;i<n;i++){
        cin>>m;
        v.push_back(m);
    }
    cin>>k;
    sort(v.begin(),v.end());
    int temp;
    for(int i=0;i<v.size();i++){
        int a[v.size()]; int f[k+1]={0};
        for(int j=0;j<v.size();j++)a[j]=v[j];
        
        sum(i, a, v.size(),2*k,0 );
    }
    
}