#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    //Priority queue
    //Set

    vector <int> dijkstra(int V, vector<vector<int>> iadj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        // int distance[V]={1e9};
        vector<vector<int>> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<iadj[i].size();j++){
                adj[i].push_back({iadj[i][j][0],iadj[i][j][1]});
                adj[iadj[i][j][0]].push_back({i,iadj[i][j][1]});
            }
        }

        // for(auto i:adj){
        //     for(auto j:i)cout<<j[0]<<j[1];
        //     cout<<endl;
        // }

        vector<int> distance(V,1e9);
        distance[S]=0;
        while(!pq.empty()){
            int n=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto i:adj[n]){
                int next=i[0];
                int dis=i[1];
                if(dis+d< distance[next]){
                    distance[next]=dis+d;
                    pq.push({distance[next],next});
                }
            }
        }
        return distance;
    }

int32_t main(){
    int n;cin>>n;
    vector<vector<int>> adj[n];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        // adj[y].push_back({x,z});
    }
    int s;cin>>s;
    //distance array
    //min heap- priority queue
    //source node
    int distance[n];
    //distance of the source node =0
    distance[0]=0;
    //this goes into priority queue

    vector<int> v=dijkstra(n,adj,s);
    for(auto  i:v)cout<<i<<' ';

}