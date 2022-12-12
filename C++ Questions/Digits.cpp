#include<bits/stdc++.h>
using namespace std;
void greatest(int *a,int n, int m, int p){
    sort(&a[0],&a[n-1]);
    int q=n-m-p-1; int r=m+p+1;
    int z[r];
    z[0]=0;
    for(int i=0;i<q;i++){
        z[0]+=a[n-1-i]*pow(10,q-1);
        cout<<a[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<r;i++){cout<<z[i]<<' ';}

}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int m;cin>>m;
    int plus=0,minus=0;
    char l[2*m+1];
    for(int i=0;i<(2*m+1);i++){
        cin>>l[i];
        if(l[i]=='+')plus++;
        if(l[i]=='-')minus++;
    }
    cout<<minus<<plus<<endl;
    greatest(a,n,minus,plus);
}