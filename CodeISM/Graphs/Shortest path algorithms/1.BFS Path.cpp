#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> path(n+1,0);
    
    path[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==n)break;

        for(auto i:adj[x]){
            if(path[i]==0){
                path[i]=x;
                q.push(i);
            }
        }
    }

    if(path[n]==0)cout<<"IMPOSSIBLE"<<endl;
    else{
        // vector<int> v;
        stack<int> s;
        while(path[n]!=n){
            s.push(n);
            n=path[n];
        }
        cout<<s.size()+1<<endl;
        cout<<n<<' ';
        while(!s.empty()){
            cout<<s.top()<<' ';
            s.pop();
        }
    }
}