#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(n+1,vector<int>(n+1,0));
    
    //for non directional graph
        //for edge weights not assigned
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        v[x][y]=1;
        v[y][x]=1;
    }
        //for edge weights assigned
    for(int i=0;i<m;i++){
        int x,y,weight;cin>>x>>y>>weight;
        v[x][y]=weight;
        v[y][x]=weight;
    }
    
    //for directional graphs
        //without edge weights
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        v[x][y]=1;
    }
        //with weights
    for(int i=0;i<m;i++){
        int x,y,weight;cin>>x>>y>>weight;
        v[x][y]=weight;
    }


    //using linked list
    vector<vector<int>> l(n+1);
    
    //non-directional
        //without weights
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        l[x].push_back(y);
        l[y].push_back(x); // in directional this is removed
    }
        //with weights
    vector<vector<pair<int,int>>> lw(n+1);
    for(int i=0;i<m;i++){
        int x,y,weight;
        lw[x].push_back({y,weight});
        lw[y].push_back({x,weight}); //in directional this is removed
    }


}