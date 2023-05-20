#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int x=0;
    for(int i=0;i<=n;i++){
        x+=1LL<<i;
        int temp;
        for(int j=0;j<=n-i;j++){
            temp=x<<j;
            for(int k=0;k<n;k++){
                if(temp & (1LL<<k))cout<<v[k]<<" ";
            }
            cout<<endl;
        }
    }

}