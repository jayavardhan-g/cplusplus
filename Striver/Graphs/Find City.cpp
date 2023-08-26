#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        vector<vector<int>> v(n,vector<int>(n,1e9));
        for(int i=0;i<m;i++){
            v[edges[i][0]][edges[i][1]]=edges[i][2];
            v[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++)v[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[i][j]=min(v[i][j], v[i][k]+v[k][j]);
                }
            }
        }
        int r=-1,minn=1e9;
        for(int i=0;i<n;i++){
            // bool x=1;
            int count=0;
            for(int j=0;j<n;j++){
                // if(v[i][j]!=1e9 && i!=j)count++;
                // if(v[i][j]>distanceThreshold){
                //     x=0;continue;
                // }
                if(v[i][j]<=distanceThreshold)count++;
            }
            if(count<=minn){
                minn=count;
                r=i;
            }
            
        }
        return r;
    }

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(m,vector<int>(3));
    for(int i=0;i<m;i++)cin>>v[i][0]>>v[i][1]>>v[i][2];
    int d;cin>>d;
    cout<<findCity(n,m,v,d);
}