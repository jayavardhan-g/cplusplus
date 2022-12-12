#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <vector <int>> Matrix={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 18} };

    int d1=0,d2=0;
    int l=Matrix.size();
    cout<<l<<endl;
    for (int i=0;i<l;i++){
        d1+=Matrix[i][i];
        d2+=Matrix[l-1-i][i];

    }
    cout<<d1<<endl<<d2;

}