#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

class DisjointSet{
    vector<vector<pair<int,int>>> parent;
    vector<vector<int>> size;
    public:
    DisjointSet(int n,int m){
        parent.resize(n+1,vector<pair<int,int>>(m+1));
        size.resize(n+1,vector<int>(m+1,1));
        for(int i=0;i<n+1;i++)for(int j=0;j<m+1;j++)parent[i][j]={i,j};
    }
    pair<int,int> findUparent(pair<int,int> node){
        if(parent[node.first][node.second]==node)return node;
        else return parent[node.first][node.second]=findUparent(parent[node.first][node.second]);
    }
    void unionBySize(pair<int,int> u,pair<int,int> v){
        pair<int,int> ul_u = parent[u.first][u.second];
        pair<int,int> ul_v = parent[v.first][v.second];
        if(ul_u == ul_v)return ;
        
        if(size[ul_u.first][ul_u.second]> size[ul_v.first][ul_v.second]){
            parent[ul_v.first][ul_v.second]=ul_u;
            size[ul_u.first][ul_u.second]+= size[ul_v.first][ul_v.second];
        }else{
            parent[ul_u.first][ul_u.second]=ul_v;
            size[ul_v.first][ul_v.second]+= size[ul_u.first][ul_u.second];
        }
    }
    int findSize(pair<int,int> node){
        pair<int,int> ul_node= findUparent(node);
        return size[ul_node.first][ul_node.second];
    }
    
};

    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        DisjointSet ds(n,n);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(grid[i][j]==1){
            for(int k=0;k<4;k++){
                int x= i+dx[k];
                int y= j+dy[k];
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                    if(ds.findUparent({x,y})== ds.findUparent({i,j}))continue;
                    else ds.unionBySize({x,y}, {i,j});
                }
            }
        }

        set<pair<int,int>> f;
        // for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        //     if(grid[i][j]==1){
        //         pair<int,int> t=ds.findUparent({i,j});
        //         if(f.find(t)== f.end()){
        //             f.insert(t);
        //             cout<<t.first<<' '<<t.second<<'-'<<ds.findSize(t)<<endl;
        //         }
        //     }
        // }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int tans=1;
                    set<pair<int,int>> s;
                    for(int k=0;k<4;k++){
                        int x= i+dx[k];
                        int y= j+dy[k];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                            pair<int,int> t= ds.findUparent({x,y});
                            if(s.find(t)==s.end()){
                                s.insert(t);
                                tans+=ds.findSize(t);
                            }
                        }
                    }
                    ans=max(tans,ans);
                }
            }
        }
        return ans;
    }

// int rec(int i,int j,vector<vector<int>> &grid, vector<vector<bool>> &vis){
//     int n=vis.size();
//     // if(vis[i][j])return;
//     int dx[4]={-1,0,1,0};
//     int dy[4]={0,1,0,-1};
//     vis[i][j]=1;

//     int r=1;

//     for(int k=0;k<4;k++){
//         if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<n && grid[i+dx[k]][j+dy[k]]==1 && !vis[i+dx[k]][j+dy[k]]){
//             r+= rec(i+dx[k],j+dy[k],grid,vis);
//         }
//     }

//     return r;
// }

int32_t main(){
    int n;cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>grid[i][j];
    cout<<MaxConnection(grid);
    // cout<<endl<<endl<<endl;
    // vector<vector<bool>> vis(n,vector<bool>(n,0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(!vis[i][j])cout<<i<<' '<<j<<'-'<<rec(i,j,grid,vis)<<endl;
    //     }
    // }
}