// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/exponential-subset-f78d066f/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int sum;
bool dp[100][10001];

bool rec(int i,int sum){
    if(sum==0)return 1;
    if(i==n)return 0;
    if(dp[i][sum]!=-1)return dp[i][sum];

    bool p =0;
    if(v[i]<=sum) p=rec(i+1,sum-v[i]);
    if(p)return dp[i][sum]=1;
    bool np= rec(i+1,sum);
    if(np)return dp[i][sum]= 1;
    
    return dp[i][sum]= 0;
}

bool sol(int x){
    while(x<=sum){
        if(rec(0,x))return 1;
        x*=x;
    }
    return 0;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    sum=0;
    v.resize(n);for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=0;i<n;i++){
        if(sol(v[i]*v[i]))cout<<1<<' ';
        else cout<<0<<' ';
    }
}

int main(){
	int t;cin>>t;
	while(t--){
        solve();
        cout<<endl;
    }
}