//https://www.spoj.com/problems/NOTATRI/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<int> v;
int n;

int cases(int l){
    int lo=0,hi=n-1,m;
    int ind = n;
    while(lo<=hi){
        m = lo +(hi-lo)/2;

        if(v[m]>l){
            ind = m;
            hi = m-1;
        }else{
            lo= m+1;
        }
    }
    return n-ind;

}

int32_t main(){
    cin>>n;
    while(n){
        v.resize(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        cout<<endl;
        int invalid =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                invalid+= cases(v[i]+v[j]);
            }
        }
        cout<<invalid<<endl;
        
        
        
        cin>>n;
    }
}