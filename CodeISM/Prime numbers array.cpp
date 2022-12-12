#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int  n=5e6+1;
    vector<int> v(n,1);
    // for(int i=2;i*i<n;i++){
    //     if(v[i]==1){
    //         for(int j=i*i;j<n;j=j+i){
    //         v[j]=0;
    //         }
    //     }
    // }
    // int i;cin>>i;
    // if (v[i]==0)
    // {
    //     cout<<i<<" is not prime";
    // }else cout<<i<<" is prime";
    for(int i=3;i<n;i++){v[i]=1;}
        for(int i=3;i*i<n;i+=2){
            if(v[i]==0)continue;
            for(int j=i*i;j<n;j+=i)v[j]=0;
        }

}
