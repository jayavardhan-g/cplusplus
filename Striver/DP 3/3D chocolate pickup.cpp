//www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int m=-1e8;
int mem(int i,int j1,int j2,vector<vector<int>> &v,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>(v[0].size()-1)|| j2<0 || j2>(v[0].size()-1))return m;
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    if(i==v.size()-1){
        if(j1==j2)return dp[i][j1][j2]=v[i][j1];
        else return dp[i][j1][j2]=v[i][j1]+v[i][j2];
    }
    int add;
    if(j1==j2)add=v[i][j1];
    else add=v[i][j1]+v[i][j2];
    int ans=INT_MIN;
    for(int k=-1;k<2;k++){
        for(int l=-1;l<2;l++){
            ans=max(ans,add+mem(i+1,j1+k,j2+l,v,dp));
        }
    }
    return dp[i][j1][j2]=ans;
}
int tb(vector<vector<int>> &v){
    int n=v.size(),m=v[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2)dp[n-1][j1][j2]=v[n-1][j1];
            else dp[n-1][j1][j2]=v[n-1][j1]+v[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                
                int add,ans=INT_MIN; 
                if(j1==j2)add=v[i][j1];
                else add=v[i][j1]+ v[i][j2];

                for(int k=-1;k<2;k++){
                    for(int l=-1;l<2;l++){
                        if(j1+k<0||j1+k>m-1||j2+l<0||j2+l>m-1)continue;
                        ans=max(ans,add+dp[i+1][j1+k][j2+l]);
                    }
                }

                dp[i][j1][j2]=ans;

            }
        }
    }
    return dp[0][0][m-1];
}

int space(vector<vector<int>> &v){
    int n=v.size();
    int m=v[0].size();
    vector<vector<int>> sp(m,vector<int>(m,0));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2)sp[j1][j2]=v[n-1][j1];
            else sp[j1][j2]=v[n-1][j1]+v[n-1][j2];
        }
    }
    for(int i=n-2;i>=0;i++){
      vector<vector<int>> curr(m,vector<int>(m,0));
      for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
          int add,ans=INT_MIN;
          if(j1==j2)add=v[i][j1];
          else add=v[i][j1]+v[i][j2];

          for(int l=-1;l<2;l++){
            for(int k=-1;k<2;k++){
              if(j1+l<0||j1+l>m-1||j2+k<0||j2+k>m-1)continue;
              ans=max(ans,add+sp[j1+l][j2+k]);
            }
          }
          curr[j1][j2]=ans;
        }
      }
      sp=curr;
    }
    return sp[0][m-1];

}

int32_t main(){
    // int t;cin>>t;
    // while(t--){
        int n;cin>>n;
        int m;cin>>m;
        vector<vector<int>> v(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cin>>v[i][j];
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // cout<<mem(0,0,m-1,v,dp);
        // cout<<tb(v)<<endl;
        cout<<space(v);
    // }
    
}