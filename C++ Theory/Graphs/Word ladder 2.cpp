#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<vector<string>> findSequences(string start, string end, vector<string>& W){
    queue<vector<string>> q;
    q.push({start});
    vector<string> clear;
    clear.push_back(start);
    int level=0;
    unordered_set<string> s(W.begin(),W.end());
    vector<vector<string>> r;

    while(!q.empty()){
        vector<string> temp=q.front();
        string a=temp.back();
        q.pop();
        if(temp.size()>level){
            level++;
            for(auto i:clear)s.erase(i);
            clear.clear();
        }

        if(a==end){
            if(r.size()==0){
                r.push_back(temp);
            }
            else if(r[0].size()==temp.size()){
                r.push_back(temp);
            }
        }

        for(int i=0;i<start.length();i++){
            char orig=a[i];
            for(char c='a';c<='z';c++){
                a[i]=c;
                if(s.find(a)!=s.end()){
                    temp.push_back(a);
                    clear.push_back(a);
                    q.push(temp);
                    temp.pop_back();
                }
            }
            a[i]=orig;
        }
    }
    return r;
}

int32_t main(){
    int n;cin>>n;
    vector<string> d(n);
    for(int i=0;i<n;i++)cin>>d[i];
    string s,t;
    cin>>s>>t;

    vector<vector<string>> v;
    v=findSequences(s,t,d);
    for(auto i:v){for(auto j:i)cout<<j<<' '; cout<<endl;}
}