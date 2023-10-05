#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
	// bool isBipartite(int V, vector<vector<int>> &adj){
	//     int color[V];
	//     memset(color,-1,sizeof(color));
	//     for(int j=0;j<V;j++){
	//         if(color[j]!=-1)continue;
	//         queue<int> q;
    // 	    q.push(j);
    // 	    color[j]=1;
    // 	    while(!q.empty()){
    // 	        int node=q.front();
    // 	        int c=color[node]==1?2:1;
    // 	        q.pop();
    // 	        for(auto i:adj[node]){
    // 	            if(color[i]==-1){
    // 	                q.push(i);
    // 	                color[i]=c;
    // 	            }else{
    // 	                if(c!=color[i])return 0;
    // 	            }
    // 	        }
	//         }
	        
	//     }
	//     return 1;
	// }

	bool rec(int i,int color[],vector<vector<int>> &adj){
		bool r=1;
		int c=color[i]==2?1:2;

		for(auto next:adj[i]){
			if(color[next]==-1){
				color[next]=c;
				r=r & rec(next,color,adj);
				if(!r)return 0;
			}
			else{
				if(color[next]!=c)return 0;
			}
		}
		return 1;
	}

	bool isBipartite(int n,vector<vector<int>> &adj){
		int color[n];
		memset(color,-1,sizeof(color));
		for(int i=0;i<n;i++){
			if(color[i]==-1){
				color[i]=1;
				if(!rec(i,color,adj))return 0;
			}
		}
		return 1;
	}

int32_t main(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<isBipartite(n, adj);

}