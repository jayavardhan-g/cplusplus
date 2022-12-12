#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    int s;
    cin>>s;
    int i=0,j=m-1;
    
    while( a[i][j]!=s && i<n &&j<m ){
        if(s>a[i][j])i++;
        else j--;
    }
    if(s==a[i][j]) cout<<"Element found";
    
    else cout<<"Element not found";
}