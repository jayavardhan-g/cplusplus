#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int backtrack[n+1];
        set<pair<int,int>> seet;
        for(int i=0;i<n+1;i++)backtrack[i]=i;
        vector<int> distance(n+1,1e9);
        // memset(distance,1e9,sizeof(distance));
        // for(int i=0;i<n;i++)distance[i]=1e9;
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        pq.push({0,1});
        seet.insert({0,1});

        distance[1]=0;
        while(!seet.empty()){
            auto n=*(seet.begin());
            int node=n.second;
            int d=n.first;
            seet.erase(n);
            for(auto next:adj[node]){
                if(d+next.second < distance[next.first]){
                    seet.erase({distance[next.first], next.first});
                    distance[next.first]=d+next.second;
                    backtrack[next.first]=node;
                    seet.insert({distance[next.first], next.first});
                }
            }
        }
        // while(!pq.empty()){
        //     auto n=pq.top();
        //     int node=n.second;
        //     int d=n.first;
        //     pq.pop();
        //     for(auto next:adj[node]){
        //         if(d+next.second < distance[next.first]){
        //             distance[next.first]=d+next.second;
        //             backtrack[next.first]=node;
        //             pq.push({distance[next.first], next.first});
        //         }
        //     }
        // }
        vector<int> r;
        int i=n;
        while(backtrack[i]!=i){
            r.push_back(i);
            i= backtrack[i];
        }
        r.push_back(i);
        reverse(r.begin(),r.end());
        if(r[0]==1)return r;
        else return {-1};
    }
int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(m, vector<int>(3));
    for(int i=0;i<m;i++)cin>>v[i][0]>>v[i][1]>>v[i][2];

    vector<int> r=shortestPath(n,m,v);
    for(auto i:r)cout<<i<<' ';
    
}