#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int f;
	cin>>f;
	int index=-1;
	for(int i=0;i<n;i++){
		if(f==a[i]){ index=i;break;}
	}
	cout<<index;
}