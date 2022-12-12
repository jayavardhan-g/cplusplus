#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    
    int k;cin>>k;
    int ans=0;
    for(int i=0;i<n-k;i++){
        set<int> s;
        int l=0;
        int j;
        for(j=i;j<(k+i);j++){
            if(s.find(a[j])==s.end()){
                s.insert(a[j]);
            }
            else break;
            l+=a[j];
        }
        s.clear();
        if(j!=i+k)continue;

        ans=max(l,ans);
        
    }
    cout<<ans;
}