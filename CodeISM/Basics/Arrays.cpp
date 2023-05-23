#include <bits/stdc++.h>
using namespace std;
const int Max=500001;
int lcm(vector <int> v){
    int ans=1;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        for(int j=(i+1);j<v.size();j++){
            if((v[j]%v[i])==0){v[i]=1;break;}
        }
        ans*=v[i];
    }
    return ans;
}
int hcf(vector<int> v){
    sort(v.begin(),v.end());
    int i=v[0];
    for(i;i>0;i--){
        int j=1;
        for(j;j<v.size();j++){
            if(v[j]%i>0)break;
        }
        if(j==v.size())break;
    }
    return i;
}
void print(vector<int> v){
    for(int i=0;i<v.size();i++)cout<<v[i]<<' ';
}
int main(){
    int a[5]={2,2,4,4,6};
    vector<int> v;
    for(int i=0;i<5;i++){
        int l=i+1;
        for(int j=i+1;j<5;j++){
            if(a[j]%a[i]==0)break;
            l++;
        }
        if(l==5)v.push_back(a[i]);

    }
}