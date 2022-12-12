#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t Single(int a,bool *p){
    int sum=0;
    for(int i=0;i*i<=a;i++){
        if(p[i]==1&&a%p[i]==0)sum+=i;
    }
    return sum;
}

int32_t main(){
    int max=1001;
    bool p[max];
    memset(p,1,sizeof(p));
    p[0]=0;
    p[1]=0;
    for(int i=2;i*i<max;i++){
        if(p[i]==1)for(int j=i;j<max;j+=i){
            p[j]=0;
        }
    }
    cout<<Single(12,p);
    // Sum of all prime divisors for 1 number
}