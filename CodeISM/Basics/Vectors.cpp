#include<bits/stdc++.h>
using namespace std;
void reverse (int *a,int n){
    
    cout<<n<<endl;;
    for(int i=0;i<n/2;i++){
        a[i]=a[i]+a[n-1-i];
        a[n-1-i]=a[i]-a[n-1-i];
        a[i]=a[i]-a[n-1-i];
    }
}
void reverse (vector<int> &a){
    int n=a.size();
    cout<<n<<endl;;
    for(int i=0;i<n/2;i++){
        a[i]=a[i]+a[n-1-i];
        a[n-1-i]=a[i]-a[n-1-i];
        a[i]=a[i]-a[n-1-i];
    }
}

int main(){
    vector<int> v;
    int n=0;
    int a[11]={0};
    while(n!=-1){
        cin>>n;
        v.push_back(n);
        a[n+1]=n;
    }

    sort(v.begin(),v.begin()+5);
    sort(a,a+5);

    for(auto x:v)cout<<x<<' ';
    cout<<endl;
    for(auto x:a)cout<<x<<' ';
    cout<<endl;
    n=sizeof(a)/sizeof(a[0]);
    reverse(a,n);
    for(auto x:a)cout<<x<<' ';
    cout<<endl;
    reverse(v);
    for(auto x:v)cout<<x<<' ';
    cout<<endl;
}