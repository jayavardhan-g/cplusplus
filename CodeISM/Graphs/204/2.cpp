//https://www.spoj.com/problems/KATHTHI/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve(){
    int n,m;cin>>n>>m;
    char v[n][m];
    for(int i=0;i<n;i++){
        string t;cin>>t;
        for(int j=0;j<m;j++)v[i][j]=t[j];
    }
    // int dis[n][m];
    // memset(vis,0,sizeof(v));
    vector<vector<int>> dis(n,vector<int>(m,1e9));
    dis[0][0]=0;
    deque<pair<int,pair<int,int>>> dq;
    dq.push_back({0,{0,0}});
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    while(!dq.empty()){
        int d= dq.front().first;
        int x= dq.front().second.first;
        int y= dq.front().second.second;
        dq.pop_front();

        for(int i=0;i<4;i++){
            int nx= x+dx[i],ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(v[nx][ny]==v[x][y]){
                    if(dis[nx][ny]>d){
                        dis[nx][ny]=d;
                        dq.push_front({d,{nx,ny}});
                    }
                }else{
                    if(dis[nx][ny]>d+1){
                        dis[nx][ny]=d+1;
                        dq.push_back({d+1,{nx,ny}});
                    }
                }
            }
        }
    }
    cout<<dis[n-1][m-1]<<endl;
}

int32_t main(){
    int t;cin>>t;
    while(t--)solve();
}