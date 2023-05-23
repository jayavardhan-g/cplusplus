#include<bits/stdc++.h>
#define int long long
using namespace std;
int M=1e6+1;
int32_t main(){
    int phi[M];
    for(int i=0;i<M;i++){
        phi[i]=i;
    }
    for(int i=2;i<M;i++){
        if(phi[i]!=i)continue;
        for(int j=i;j<M;j+=i){
            phi[j]=phi[j]-phi[j]/i;
        }
    }
}