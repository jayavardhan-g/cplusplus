#include <bits/stdc++.h>
using namespace std;

int sq(int x){
	return x*x;
	}
int sos(int x,int y){
	int z=sq(x+y);
	return z;
	}
int main(){
	int a=4,b=8;
	int total=sos(a,b);
	cout<<total;
	}