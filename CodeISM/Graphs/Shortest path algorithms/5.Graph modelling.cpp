//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long

int32_t main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{1,k}});
    map<pair<int,int>,int> costs;
    // for(int i=1;i<n;i++){
    //     for(int j=0;j<=k;j++){
    //         costs[{i,j}]=1e9;
    //     }
    // }
    costs[{1,k}]=0;
    while(!pq.empty()){
        int cost= pq.top().first;
        int node= pq.top().second.first;
        int left= pq.top().second.second;
        pq.pop();
        for(auto i:adj[node]){
            int c= i.second;
            int next= i.first;

            if(left>0 && (costs.find({next,k-1})==costs.end() || costs[{next,k-1}]>cost) ){
                costs[{next,k-1}]=cost;
                pq.push({cost,{next,k-1}});
            }
            if( costs.find({next,left})==costs.end() || costs[{next,left}]>cost+c){
                pq.push({cost+c,{next,k}});
                costs[{next,left}]=(cost+c);
            }
        }
    }
    

    // for(auto i:costs)cout<<i.first.first<<' '<<i.first.second<<' '<<i.second;
    vector<int> v(n+1,1e9);
    for(auto i:costs){
        v[i.first.first]= min(v[i.first.first],i.second);
    }
    for(int i=1;i<=n;i++)cout<<v[i]<<' ';
}