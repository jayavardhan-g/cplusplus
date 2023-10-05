#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int square(vector<int> &v){
    int ans=0;

    for(int i=0;i<v.size();i++){
        int m=v[i];
        for(int j=i;j>=0;j--){
            m=min(m,v[j]);
            if(m>=(i-j+1))ans+=1;
        }
    }
    return ans;
}
int countSquares(int n, int m, vector<vector<int>> &v) {
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1){
                v[i][j]=1+v[i-1][j];
            }
        }
    }
    // for(auto i:v){
    //     for(auto j:i)cout<<j<<" ";
    //     cout<<endl;
    // }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=square(v[i]);
    }
    return ans;
}

int32_t main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
    cout<<countSquares(n,m,v);
}