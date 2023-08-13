#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    void rec(int i,int j,vector<vector<char>> &g,vector<vector<char>> &v){
        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};
        v[i][j]='O';
        for(int k=0;k<4;k++){
            int x1=i+x[k];
            int y1=j+y[k];
            if(x1>=0 && x1<g.size() && y1>=0 && y1<g[0].size() && g[x1][y1]=='O' && v[x1][y1]=='X'){
                rec(x1,y1,g,v);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> g)
    {   
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        for(int i=0;i<n;i++){
            if(g[i][0]=='O')rec(i,0,g,ans);
            if(g[i][m-1]=='O')rec(i,m-1,g,ans);
        }
        for(int i=0;i<m;i++){
            if(g[0][i]=='O')rec(0,i,g,ans);
            if(g[n-1][i]=='O')rec(n-1,i,g,ans);
        }
        return ans;
    }
int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<char>> g(n,vector<char>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>g[i][j];
    g=fill(n,m,g);

    for(auto i:g){
        for(auto j:i)cout<<j<<' ';
        cout<<endl;
    }

}