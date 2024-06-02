//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,m;cin>>m>>n;
    vector<int> ti(n),no(n),re(n);
    for(int i=0;i<n;i++){
        cin>>ti[i]>>no[i]>>re[i];
    }
    vector<int> r(n);

    int lo=0,hi=4e7;

    int time=0;

    while(lo<=hi){
        vector<int> tr(n);
        int mid = lo+ (hi-lo)/2;
        int b=0;
        for(int i=0;i<n;i++){
            int ib = 0;
            int ibwr = mid / (ti[i]*no[i] + re[i]);
            ib += ibwr*no[i];
            
            int left= mid%(ti[i]*no[i] + re[i]);
            if(left>= ti[i]*no[i])ib+=no[i];
            else ib+= left/ti[i];
            
            tr[i] = ib;
            b+= ib;
        }

        if(b>=m){
            time= mid;
            r=tr;
            hi= mid-1;
        }else{
            lo=mid+1;
        }
    }

    cout<<time<<endl;
    int blown=0;
    for(int i=0;i<n;i++){
        if(blown==m){
            cout<<0<<' ';
        }
        else if(blown+r[i]>m){
            cout<< (blown+r[i]-m)<<' ';
            blown =m;
        }else{
            cout<<r[i]<<' ';
            blown+=r[i];
        }
    }
}