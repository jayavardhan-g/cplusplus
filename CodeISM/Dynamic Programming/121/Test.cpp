#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

void solve(char *c){
  int i=0;
  while(c[i]!='\0'){
    cout<<c[i]<<' ';
    i++;
  }
}

int32_t main(){
  char c[10];cin>>c;
  solve(c);
}