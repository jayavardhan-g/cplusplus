#include<bits/stdc++.h>
using namespace std;
#define int long long
int recursive(int x,int y){
    if(y==1)return x;
    if(y%2==0){
        x=recursive(x*x,y/2);
    }else{
        x=x*recursive(x*x,y/2);
    }
    return x;

}
int iterative(int x,int y){
    int ans=1;
    while(y!=0){
        if(y%2==1)ans*=x;

        x=x*x;
        y/=2;
    }
    return ans;
}
int32_t main(){
    int x;cin>>x;
    int y;cin>>y;
    cout<<recursive(x,y)<<endl;
    cout<<iterative(x,y);
}