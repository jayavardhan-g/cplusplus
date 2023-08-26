#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
        int CheapestFLight(int n, vector<vector<int>>& f, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        for(auto i:f)adj[i[0]].push_back({i[1],i[2]});
        
        vector<int> distance(n,1e9);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        distance[src]=0;
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            int node=i.second.second;
            int k=i.second.first;
            int d=i.first;
            // if(k<=K+1 && node==dst)return d;
            if(k>K)continue;
            
            for(auto next:adj[node]){
                if(distance[next.first]> d+next.second){
                    distance[next.first]=d+next.second;
                    pq.push({d+next.second,{k+1,next.first}});
                }
            }
        }
        return distance[dst];
        // return -1;
    }
int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> flights(m,vector<int>(3));
    for(int i=0;i<m;i++)cin>>flights[i][0]>>flights[i][1]>>flights[i][2];
    int s,t,k;
    cin>>s>>t>>k;
    cout<<CheapestFLight(n,flights,s,t,k);
}