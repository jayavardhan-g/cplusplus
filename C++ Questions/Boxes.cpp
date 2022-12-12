#include<bits/stdc++.h>
using namespace std;
static bool compare(vector<int> &v1, vector<int> &v2){
    if(v1[1]>v2[1])return true;
    return false;
}
int maximumUnits(vector<vector<int>>&b, int t) {
    sort(b.begin(),b.end(),compare);
    int ans=0;
    for(int i=0;i<b.size();i++){
        if(b[i][0]>0 && t>0){
            t--;
            ans+=b[i][1];
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> v;
    
}