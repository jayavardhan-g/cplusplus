//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/G
#include<bits/stdc++.h>
using namespace std;
#define int long long

int nu(string s){
    
}

int32_t main(){
    int n,c;cin>>n>>c;
    string s;cin>>s;

    int l=0;
    int a=0,b=0;
    int ans=0;
    for(int r=0;r<n;r++){
        if(s[r]=='a')a++;
        if(s[r]=='b')b++;

        while(l<n && a*b>c){
            if(s[l]=='a')a--;
            if(s[l]=='b')b--;

            l++;
        }

        ans= max(ans, r-l+1);
    }
    cout<<ans<<endl;
    // TODO
}