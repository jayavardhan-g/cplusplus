#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    int sum;
    cin>>sum;
    int s=0,e=0,currentsum=a[s];
    while(sum!=currentsum &&s<=e&&e<n){
	    if (sum>currentsum){
		    e++;
		    currentsum+=a[e];
	    }
	    else {
		    currentsum-=a[s];
		    s++;	
	    }
    }
    if(sum==currentsum) cout<<s<<" " <<e;
    else cout<<"There is no such subarray";
}