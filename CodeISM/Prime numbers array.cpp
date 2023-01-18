#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int  n=1e6+1;
    bool v[n];
     
    for(int i=3;i<n;i+=2){v[i]=1;}
        for(int i=3;i*i<n;i+=2){
            if(v[i]==0)continue;
            for(int j=i*i;j<n;j+=i)v[j]=0;
        }
    int t;cin>>t;
    while(t--){
        cin>>n;
        cout<<v[n]<<endl;

    }


}
