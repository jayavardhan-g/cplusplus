#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

    string findOrder(string d[], int N, int k) {
        set<int> adj[k];
        for(int i=1;i<N;i++){
            int m=min(d[i].size(),d[i-1].size());
            for(int j=0;j<m;j++){
                if(d[i][j]!=d[i-1][j]){
                    adj[d[i-1][j]-'a'].insert(d[i][j]-'a');
                    break;
                }
            }
        }
        string r;
        queue<int> q;
        int indegree[k]={0};
        for(int i=0;i<k;i++){
            for(auto next:adj[i]){
                indegree[next]++;
            }
        }
        for(int i=0;i<k;i++)if(indegree[i]==0)q.push(i);
        while(!q.empty()){
            int n= q.front();
            char c= n+'a';
            r+=c;
            q.pop();
            for(auto next:adj[n]){
                indegree[next]--;
                if(indegree[next]==0)q.push(next);
            }
        } 
        return r;
    }

int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    string d[n];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }

    string s=findOrder(d,n,k);
    cout<<s;
}