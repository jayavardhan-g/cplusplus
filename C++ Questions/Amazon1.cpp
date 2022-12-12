#include<bits/stdc++.h>
using namespace std;
#define int long long
bool compare(int i,int j){
    return i>j;
}
int Find(int *a,int n){
    int ans=0;
    vector<int> v(100000,0);
    for(int i=0;i<n;i++){v[a[i]]++;}
    sort(v.begin(),v.end(),compare);
    int i=0;
    while(v[i]!=0){
        if(v[i]%3==0)ans+=v[i]/3;
        else if(v[i]%3==2)ans+=v[i]/3+1;
        else if(v[i]%2==0)ans+=v[i]/2;
        else {return -1;}
        i++;
    }
    return ans;
}

int32_t main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<Find(a,n);

}