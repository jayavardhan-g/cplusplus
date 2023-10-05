#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

        int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        queue< pair<pair<int,int>, int>> q;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                // if(grid[i][j]==1)o++;
            }
        }
        
        while(!q.empty()){
            pair<pair<int,int>,int> node=q.front();
            q.pop();
            int i=node.first.first,j=node.first.second,c=node.second;
            // ans=max(ans,c+1);
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                q.push({{i-1,j},c+1});
                ans=max(ans,c+1);
                vis[i-1][j]=1;
            }
            if(i+1<grid.size() && !vis[i+1][j] && grid[i+1][j]==1){
                q.push({{i+1,j},c+1});
                ans=max(ans,c+1);
                vis[i+1][j]=1;
            }
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                q.push({{i,j-1},c+1});
                ans=max(ans,c+1);
                vis[i][j-1]=1;
            }
            if(j+1<grid[0].size() && !vis[i][j+1] && grid[i][j+1]==1){
                q.push({{i,j+1},c+1});
                ans=max(ans,c+1);
                vis[i][j+1]=1;
            }

        }
        
        for(int i=0;i<grid.size();i++)for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1 && !vis[i][j])return -1;
        }
        
        return ans;
    }

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
    cout<<orangesRotting(v);
}