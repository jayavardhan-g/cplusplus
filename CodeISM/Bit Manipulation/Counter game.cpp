//https://www.hackerrank.com/challenges/counter-game/problem
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

string counterGame(long n) {
    // string w= "Louise";
    // string l="Richard";
    // while(n){
    //     if( !(n&(n-1)) ){
    //         int z = findpow(n);
    //         if(z&1)return w;
    //         else return l;
    //     }else{
    //         n= n- msb(n);
    //         swap(w,l);
    //     }
    // }
    // return w;
    int turns=0;
    // for(int i=0;i<64;i++){
    //     if(!(n&(1LL<<i)))turns++;
    //     else break;
    // }
    
    long lsb = n&(-n);
    n = n|(lsb-1);
    n--;
    int set = __builtin_popcount(n);
    cout<<n<<endl;
    cout<<endl<<lsb<<' ';
    cout<<set<<endl;
    if(set&1)return "Louise";
    return "Richard";
}

void solve(){
    int n;cin>>n;
    cout<<counterGame(n);
}

int32_t main(){
    int t;cin>>t;
    while(t--)solve();
}