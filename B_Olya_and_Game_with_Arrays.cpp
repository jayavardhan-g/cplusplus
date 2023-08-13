// #include<bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long

// int base(){
//     int n;cin>>n;
//     vector<vector<int>> v(n);
    
//     for(int i=0;i<n;i++){
//         int x;cin>>x;
//         for(int j=0;j<x;j++){
//             int y;cin>>y;
//             v[i].push_back(y);
//         }
//         sort(v[i].begin(),v[i].end());
//     }
//     int ans=0,m=INT_MAX,minn=INT_MAX;
//     for(int i=0;i<n;i++){
//         ans+=v[i][1];
//         m=min(m,v[i][1]);
//         minn=min(minn,v[i][0]);
//     }
//     ans= ans-m+minn;
//     return ans;
// }
// int32_t main(){
//     int t;cin>>t;
//     while(t--){
//         cout<<base()<<endl;
//     }
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>arr[n];
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int a;
                cin>>a;
                arr[i].push_back(a);
            }
        }
        for(int i=0;i<n;i++){
            sort(arr[i].begin(),arr[i].end());
            vec.push_back({arr[i][1],arr[i][0]});
        }
        sort(vec.begin(),vec.end());
        int x=INT_MAX;
        for(int i=0;i<n;i++){
            x=min(x,vec[i].second);
        }
        int ans=x;
        for(int i=1;i<n;i++){
            ans+=vec[i].first;
        }
        cout<<ans<<endl;
    }
    
}