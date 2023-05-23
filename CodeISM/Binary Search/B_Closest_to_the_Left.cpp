#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int>v(n);for(int i=0;i<n;i++)cin>>v[i];
    vector<int>a(k);for(int i=0;i<k;i++)cin>>a[i];
 
    for(int i=0;i<k;i++){
        int x=a[i];
        int lo=0,hi=n-1,m;
        int pos=-1;
        
        if(v[n-1]<=x){cout<<n<<endl;continue;}
 
        while(lo<=hi){
            m= lo+ (hi-lo)/2;
            if(v[m]>x)hi=m-1;
            else {
                pos=m;
                lo=m+1;
            }
        }
        cout<<pos+1<<endl;
    }
}