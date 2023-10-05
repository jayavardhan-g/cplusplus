#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// class DisjointSet{
//     vector<int> rank,parent;
//     public:
//     DisjointSet(int n){
//         rank.resize(n+1,0);
//         parent.resize(n+1);
//         for(int i=0;i<n+1;i++)parent[i]=i;
//     }
//     int findUParent(int node){
//         if(parent[node]==node)return node;
//         else return parent[node]=findUParent(parent[node]);
//     }
//     void unionBySize(int u,int v){
//         int ul_u= findUParent(u);
//         int ul_v= findUParent(v);

//         if(ul_v==ul_u)return ;
        
//         if(rank[ul_u]>rank[ul_v]){
//             parent[ul_v]=ul_u;
//         }
//         else if(rank[ul_u]<rank[ul_v]){
//             parent[ul_u]=ul_v;
//         }
//         else {
//             parent[ul_u]=ul_v;
//             rank[ul_v]++;
//         }
//     }
// };

class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)parent[i]=i;
    }
    int findUParent(int node){
        if(parent[node]==node)return node;
        else return parent[node]=findUParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ul_u= findUParent(u);
        int ul_v= findUParent(v);

        if(ul_v==ul_u)return ;
        
        if(size[ul_u]>size[ul_v]){
            parent[ul_v]=ul_u;
            size[ul_u]+= size[ul_v];
        }
        else {
            parent[ul_u]=ul_v;
            size[ul_v]+= size[ul_u];
        }
    }
};

int32_t main(){
    // int n;cin>>n;
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(3,2);
    // ds.unionBySize(4,2);
    ds.unionBySize(5,6);
    ds.unionBySize(6,7);
    if(ds.findUParent(2)==ds.findUParent(5))cout<<"Same"<<endl;
    else cout<<"Not same"<<endl;
    ds.unionBySize(7,2);
    if(ds.findUParent(2)==ds.findUParent(5))cout<<"Same"<<endl;
    else cout<<"Not same"<<endl;
    // ds.unionBySize(1,2);
}