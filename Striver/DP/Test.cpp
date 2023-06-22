#include<bits/stdc++.h>
using namespace std;
int main(){

        long long int t;
       cin>>t;
       while(t--){
       long long int n,m,h,ans=0,i;
       cin>>n >>m >>h;

        long long int p=min(n,m);
       vector<long long int>a(n),b(m);
       for(i=0;i<n;i++){
       cin>>a[i] ;
       }
       for(i=0;i<m;i++){
       cin>>b[i] ;
       }
       sort(a.begin(),a.end());
       reverse(a.begin(),a.end());
       sort(b.begin(),b.end());
       reverse(b.begin(),b.end());
       for(i=0;i< p;i++){
       ans=ans+ min(a[i],h*b[i]);
       }
       cout<<ans<<endl;
       }
}