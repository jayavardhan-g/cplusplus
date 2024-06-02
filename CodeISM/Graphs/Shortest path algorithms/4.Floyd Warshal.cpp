#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// Distance from every node to every other node

int32_t main(){
    int n,m;cin>>n>>m;
    int distance[n+1][n+1];
    for(int i=0;i<n+1;i++)for(int j=0;j<n+1;j++)distance[i][j]=i==j?0:1e9;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y,d;cin>>x>>y>>d;
        adj[x].push_back({y,d});
        distance[x][y]=d;
    }

    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            int x=distance[i][j]==1e9?-1:distance[i][j];
            cout<<x<<" ";
        }
        cout<<endl;
    }
}