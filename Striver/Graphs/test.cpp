#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
    int countPairs(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        int  ans=0;
        int i=0;
        int j=v.size()-1;
        while(i<j){
            int x=v[i]+v[j];
            if(x>=target){
                j--;
            }else{
                ans+=(j-i);
                i++;
            }
        }
        return ans;
    }

int32_t main(){
    int n;cin>>n;
    vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
    int x;
    cin>>x;
    cout<<countPairs(v,x);
}