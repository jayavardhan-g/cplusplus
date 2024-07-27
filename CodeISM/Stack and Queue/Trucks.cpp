//https://www.spoj.com/problems/STPAR/
#include<bits/stdc++.h>
using namespace std;
// #define int long long

int32_t main(){
    int n;
    cin>>n;
    while(n!=0){
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        stack<int> st;


        int j=1;
        for(int i=0;i<n;i++){
            if( !st.empty() && st.top()==j){
                st.pop();
                j++;     
                i--;       
            }
            else if(a[i]==j)j++;
            else st.push(a[i]);
        }

        while( !st.empty() && st.top()==j ){
            st.pop();
            j++;
        }

        if(j==n+1)cout<<"yes"<<endl;
        else cout<<"no"<<endl;

        cin>>n;
    }
}