//https://www.spoj.com/problems/BITMAP/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve(){
    int n;cin>>n;
    int m;cin>>m;
    int a[n][m];
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        string t;cin>>t;
        for(int j=0;j<m;j++){
            if(t[j]=='0')a[i][j]=-1;
            else {
                a[i][j]=0;
                q.push({{i,j},0});
            }
        }
    }

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    while(!q.empty()){
        auto t= q.front();
        q.pop();
        int x= t.first.first;
        int y= t.first.second;
        int d= t.second;
        // a[x][y]=d;
        for(int i=0;i<4;i++){
            if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && a[x+dx[i]][y+dy[i]]==-1){
                a[x+dx[i]][y+dy[i]]=d+1;
                q.push({{x+dx[i],y+dy[i]},d+1});
            }
        }
    }
    for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<' '; cout<<endl;}
    
}

int32_t main(){
    int t;cin>>t;
    while(t--)solve();
}