#include <bits/stdc++.h>
using namespace std;
class Lavda{
    int n;
    vector<pair<string,pair<int,int>>> v;

};

int main() {
	int n;cin>>n;
	vector<Lavda> v(1);
	map <string,int> m;
    string s;
    getline(cin,s);
	while(n--){
        getline(cin,s);
        string name=s.substr(9);
        string ins=s.substr(0,8); 
		if(ins=="add-user"&&m[name]==0){
			m[name]=v.size();
			Lavda L;
            v.push_back(L);
			cout<<"success"<<endl;
		}
		else cout<<"failure"<<endl;


        if(	)
	}
	
}