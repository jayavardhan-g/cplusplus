//https://codeism.contest.codeforces.com/group/qXv2tukHZE/contest/309847/problem/A
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve(){
    int m,n;
    cin>>m>>n;
    int xxor= n;
    int aand= (m-n)/2;

    // cout<<xxor<<' '<<aand<<endl;
    int a=0,b=0;
    for(int i=0;i<64;i++){
        bool xx = xxor&(1LL<<i);
        bool aa = aand&(1LL<<i);

        if( xx ){
            if(aa){
                cout<<-1<<endl;
                return;
            }else{
                b = b|(1LL<<i);
            }
        }else{
            if(aa){
                a= a|(1LL<<i);
                b= b|(1LL<<i);
            }
        }
    }
    cout<<a<<' '<<b<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);                       
    cout.tie(0);
    
    int t;cin>>t;
    while(t--)solve();
}