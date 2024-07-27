//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
#include<bits/stdc++.h>
using namespace std;
// #define int long long

int32_t main(){
    int n,p;
    cin>>n>>p;
    int v[n];for(int i=0;i<n;i++)cin>>v[i];

    int sum=0;
    for(int i=0;i<n;i++)sum+=v[i];

    int ans = 0;
    ans+= (p/sum)*n;
    
    int x=p%sum;
    
    // cout<<ans<<endl;
    int r=0,l=0;
    int sl=n;
    int start=1;

    sum=0;
    while(r<2*n-1){
        sum+= v[r%n];

        while(sum-v[l]>=x){
            sum-=v[l%n];
            l++;
        }

        if(sum>=x && sl>r-l+1){
            sl=r-l+1;
            start=(l%n)+1;
        }

        r++;
    }
    ans+=sl;
    cout<<start<<' '<<ans<<endl;
    // TODO
}