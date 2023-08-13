#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
    set<vector<pair<int,int>>> s;
    
    bool vis[n][m]={0};

    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && v[i][j]){
                vector<pair<int,int>> t;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    t.push_back({x-i,y-j});
                    q.pop();
                    for(int z=0;z<4;z++){
                        if(x+dx[z]>=0 && x+dx[z]<n && y+dy[z]>=0 && y+dy[z]<m && !vis[x+dx[z]][y+dy[z]] && v[x+dx[z]][y+dy[z]]==1){
                            q.push({x+dx[z], y+dy[z]});
                            vis[x+dx[z]][y+dy[z]]=1;
                        }
                    }
                }
                sort(t.begin(),t.end());
                s.insert(t);
            }
        }
    }
    cout<<s.size();
}