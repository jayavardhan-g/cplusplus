#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];

    
            int i=0,j=0;
            while(i<n&&j<m){
                if(a[i]>b[j]){
                    int temp=a[n-1];
                    for(int k=n-1;k>i;k--){
                        a[k]=a[k-1];
                    }
                    a[i]=b[j];
                    for(int k=j;k>0;k--){
                        b[k]=b[k-1];
                    }
                    b[0]=temp;
                    j++;
                }
                else i++;
            }
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    for(int i=0;i<m;i++)cout<<b[i]<<' ';
}