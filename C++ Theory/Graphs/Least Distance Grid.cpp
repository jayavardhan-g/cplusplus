#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    bool vis[n][m]={0};
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
	        if(grid[i][j]==1){
	            vis[i][j]=1;
	            q.push({{i,j},0});
	        }
	    }
	    vector<vector<int>> g(n,vector<int> (m,0));
	    
	    while(!q.empty()){
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        int d=q.front().second;
	        q.pop();
	        g[i][j]=d;
	        
	        {
	            if(i-1>=0 && !vis[i-1][j]){
	                q.push({{i-1,j},d+1});
	                vis[i-1][j]=1;
	            }
	            if(i+1<n && !vis[i+1][j]){
	                q.push({{i+1,j},d+1});
	                vis[i+1][j]=1;
	            }
	            if(j-1>=0 && !vis[i][j-1]){
	                q.push({{i,j-1},d+1});
	                vis[i][j-1]=1;
	            }
	            if(j+1<m && !vis[i][j+1]){
	                q.push({{i,j+1},d+1});
	                vis[i][j+1]=1;
	            }
	            
	        }
	    }
	    return g;
	}

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> g(n,vector<int>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>g[i][j];

    g=nearest(g);
    for(auto i:g){
        for(auto j:i)cout<<j<<' ';
        cout<<endl;
    }
}