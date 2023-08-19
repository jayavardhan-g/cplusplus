#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});
        int ways[n]={-1};
        ways[0]=1;
        vector<int> time(n,INT_MAX);
        time[0]=0;
        while(!pq.empty()){
            auto i=pq.top();
            int d=i.first;
            int node=i.second;
            pq.pop();

            for(auto next:adj[node]){
                if(time[next.first] == next.second + d){
                    ways[next.first]+=ways[node];
                    // pq.push({time[next.first],next.first});
                }
                if(time[next.first]> next.second+d){
                    ways[next.first]=ways[node];
                    time[next.first]=next.second+d;
                    pq.push({time[next.first],next.first});
                }
            }
        }
        return ways[n-1];
    }

int32_t main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(m,vector<int>(3));
    for(int  i=0;i<m;i++)cin>>adj[i][0]>>adj[i][1]>>adj[i][2];
    cout<<countPaths(n,adj);

}