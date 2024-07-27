//https://cses.fi/problemset/task/1641
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,x;cin>>n>>x;
    pair<int,int> a[n];for(int i=0;i<n;i++){cin>>a[i].first; a[i].second=i;}
    sort(a,a+n);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int r= x - a[i].first - a[j].first;
            if(r<0)break;
            
            int lo = j+1,hi=n-1,m;

            while(lo<n && lo<=hi){
                m= lo + (hi-lo)/2;

                if(a[m].first<r){
                    lo= m+1;
                }else if(a[m].first>r){
                    hi=m-1;
                }else{
                    cout<<a[i].second+1<<' '<<a[j].second+1<<' '<<a[m].second+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}