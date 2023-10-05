#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

class DisjointSet{
    vector<vector<pair<int,int>>> parent;
    vector<vector<int>> rank;
    public:
    DisjointSet(int n,int m){
        parent.resize(n+1,vector<pair<int,int>>(m+1));
        rank.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++)for(int j=0;j<m+1;j++)parent[i][j]={i,j};
    }
    pair<int,int> findUparent(pair<int,int> node){        
        if(parent[node.first][node.second]==node)return {node.first,node.second};
        else return parent[node.first][node.second]=findUparent(parent[node.first][node.second]);
    }
    
    void unionByRank(pair<int,int> u,pair<int,int> v){
        pair<int,int> ul_v=findUparent(v),ul_u=findUparent(u);
        if(ul_v==ul_u)return;
        
        if(rank[ul_v.first][ul_v.second]>rank[ul_u.first][ul_u.second]){
            parent[ul_u.first][ul_u.second]=ul_v;
        }else if(rank[ul_u.first][ul_u.second]>rank[ul_v.first][ul_v.second]){
            parent[ul_v.first][ul_v.second]=ul_u;
        }else {
            parent[ul_v.first][ul_v.second]=ul_u;
            rank[ul_u.first][ul_u.second]++;
        }
    }
};

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        set<pair<int,int>> s;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        DisjointSet ds(n,m);
        vector<vector<int>> v(n,vector<int>(m,0));
        vector<int> r;
        for(auto i:operators){
            int x=i[0],y=i[1];
            v[x][y]=1;
            for(int k=0;k<4;k++){
                if(x+dx[k]< n && x+dx[k]>=0 && y+dy[k]<m && y+dy[k]>=0 && v[x+dx[k]][y+dy[k]]==1){
                    s.erase(ds.findUparent({x+dx[k],y+dy[k]}));
                    ds.unionByRank({x,y}, {x+dx[k],y+dy[k]});
                    // s.insert(ds.findUparent({x+dx[k],y+dy[k]}));
                }
                
            }
            for(int k=0;k<4;k++){
                if(x+dx[k]< n && x+dx[k]>=0 && y+dy[k]<m && y+dy[k]>=0 && v[x+dx[k]][y+dy[k]]==1){
                    // s.erase(ds.findUparent({x+dx[k],y+dy[k]}));
                    // ds.unionByRank({x,y}, {x+dx[k],y+dy[k]});
                    s.insert(ds.findUparent({x+dx[k],y+dy[k]}));
                }

            }
                s.insert(ds.findUparent({x,y}));
                r.push_back(s.size());
        }
        // for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(v[i][j]==1)s.insert(ds.findUparent({i,j}));
        return r;
    }

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    int k;cin>>k;
    vector<vector<int>> operators(k,vector<int>(2));
    for(int i=0;i<k;i++)cin>>operators[i][0]>>operators[i][1];
    vector<int> r=numOfIslands(n,m,operators);
    for(auto i:r)cout<<i<<' ';
}