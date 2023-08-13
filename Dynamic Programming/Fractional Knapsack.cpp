#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct item{
    int value;
    int weight;
};
double fractionalKnapsack(int W, item v[], int n)
{   
    vector<pair<double,int>> a;
    for(int i=0;i<n;i++){
        double tw = (double)v[i].value/(double)v[i].weight;
        a.push_back({tw,v[i].weight});
    }
    sort(a.begin(),a.end());
    cout<<endl<<endl;
    for(int i=n-1;i>=0;i--){
        cout<<setw(3)<<n-i-1<<' '<<a[i].first<<' '<<a[i].second<<' '<<endl;
    }
    cout<<endl;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int x=min(a[i].second, W);
        if(x<=0)break;
        W-=x;
        ans+= a[i].first * x;
    }
    return ans;
}
int32_t main(){
    int n;cin>>n;
    int W;cin>>W;
    item v[n];
    for(int i=0;i<n;i++)cin>>v[i].value>>v[i].weight;
    // for(int i=0;i<n;i++)cin>>v[i].weight;
    cout<<fractionalKnapsack(W,v,n);
}