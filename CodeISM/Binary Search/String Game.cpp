//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

bool check(string &s,string &t,int i,int j){
    if(j>=t.size()){
        return 1;
    }
    if(i>=s.size()){
        return 0;
    }

    if(s[i]==t[j]){
        i++;
        j++;
        return check(s,t,i,j);
    }
    
    return check(s,t,i+1,j);

}

int32_t main(){
    string s,t;cin>>s>>t;
    vector<int> d(s.size());
    for(int i=0;i<s.size();i++)cin>>d[i];

    // vector<int> sf(26,0),tf(26,0);
    // for(auto i:s){
    //     sf[i-'a']++;
    // }
    // for(auto i:t){
    //     tf[i-'a']++;
    // }

    // int x=0;
    // for(int i=0;i<s.size();i++){
    //     if(sf[s[i]-'a']-1>=tf[s[i]-'a']){
    //         sf[s[i]-'a']--;
    //         x++;
    //     }else break;
    // }
    // cout<<x<<endl;

    int lo=0,hi=s.size()-t.size();
    int ans;
    while(lo<=hi){
        int m = lo+(hi-lo)/2;
        string temp = s;
        for(int i=0;i<m;i++){
            temp[d[i]-1]='0';
        }
        if(check(temp,t,0,0)){
            ans= m;
            lo = m+1;
        }else{
            hi=m-1;
        }

    }
    cout<<ans;
}