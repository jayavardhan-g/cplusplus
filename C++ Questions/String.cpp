#include<bits/stdc++.h>
using namespace std;
vector<int> solution (vector<long> scores, vector<int> queries){
    int s=scores.size();
    vector<int> sum(s);
    sum[0]=scores[0];
    for(int i=1;i<s;i++){
        sum[i]=scores[i]+sum[i-1];
    }
    int j=queries.size();
    vector<int> ans(j);
    for(int i=0;i<3;i++)cout<<sum[i]<<" ";
    cout<<endl;
    for(int i=0;i<j;i++){
        ans[i]=sum[queries[i]];
        cout<<ans[i]<<' ';
    };
    return ans;
}
int main(){
    int n;cin>>n;
    vector<long> v(n);
    int l;
    for(int i=0;i<(n);i++){
        cin>>l;
        v[i]=l;
    }
    int t;cin>>t;
    vector<int> q;
    for(int i=0;i<t;i++){
        cin>>l;
        q.push_back(l);
    }
    vector<int> ans=solution(v,q);
}