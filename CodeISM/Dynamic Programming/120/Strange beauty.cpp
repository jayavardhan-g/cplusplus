//https://codeforces.com/contest/1475/problem/G
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long
int L=2e5+1;
// int dp[200001];

int32_t main(){
    // for(int i=0;i<L;i++)cout<<dp[i]<<' ';
    int t;cin>>t;
    while(t--){
        
    int n;cin>>n;
    vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    
    vector<int> dp(L);
    // memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[a[i]]= 1+ dp[a[i]];
        if(a[i]!=1)dp[a[i]]= max(dp[a[i]], 1+dp[1]);
        for(int j=2;j*j<=a[i];j++){
            if(a[i]%j==0){
                dp[a[i]] = max(dp[a[i]], 1 + dp[a[i]/j]);
                dp[a[i]] = max(dp[a[i]], 1+ dp[j]);
                // cout<<a[i]<<' '<<j<<endl;
            }
        }
        // if(a[i]!=1)dp[a[i]]+= dp[1];
        // cout<<a[i]<<' '<<dp[a[i]]<<endl;
    }
    int ans=0;
    for(int i=1;i<=a[n-1];i++){
        ans= max(dp[i],ans);
        // cout<<dp[i]<<' ';
    }
    cout<<n-ans<<endl;
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
// 		int n;
// 		cin>>n;
// 		vector<int> a(n);
// 		for(int i=0;i<n;i++) cin>>a[i];
// 		const int MAX=2e5+1;
// 		vector<int>dp(MAX);
//      // memset(dp,0,sizeof(dp));
// 		//dp[i]-> The max reside if we consider i element at the end of the beautiful array
// 		sort(a.begin(),a.end());
// 		dp[a[0]]=1; 
// 		for(int i=1;i<n;i++){
// 			dp[a[i]]=dp[a[i]]+1;
// 	        // Now I’m going through all the factors of a[i] below         
// 			if(a[i]!=1) dp[a[i]]=max(dp[a[i]],dp[1]+1);
//                                  // Here factor is 1
// 			for(int j=2;j*j<=a[i];j++){
// 				if(a[i]%j==0){
// 					dp[a[i]]=max(dp[a[i]],dp[j]+1);
//                                  // Here factor is j
// 					dp[a[i]]=max(dp[a[i]],dp[a[i]/j]+1);
//                                  // Here factor is a[i]/j
// 				}
// 			}	
// 		}

// 		int ans=0;
// 		for(int i=0;i<=a[n-1];i++) ans=max(ans,dp[i]);
// 		cout<<n-ans<<endl;	
// 	}
// }