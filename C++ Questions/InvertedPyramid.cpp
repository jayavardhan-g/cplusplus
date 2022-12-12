#include <bits/stdc++.h>
using namespace std;
int main(){
    //inverted pyramid
    //int n=5;
//    
    //for(int i=0;i<n;i++){
        //for(int j=0;j<n-i;j++){
            //cout<<"*";
        //}
        //cout<<endl;
    //}
    ////inverted pyramid after 180 degree rotation
//    
    //for(int i=0;i<n;i++){
        //for (int j=0;j<n;j++){
            //if(j<n-i-1)cout<<" ";
            //else cout<<"*";
        //}
        //cout<<endl;
    //}
    //// half pyramid using numbers
    //for(int i=1;i<=n;i++){
        //for(int j=0;j<i;j++){
            //cout<<i;
        //}
        //cout<<endl;
    //}
    ////half pyramid increasing numbers
    //int c=1;
    //for(int i=1;i<=n;i++){
        //for(int j=0;j<i;j++){
            //cout<<c++<<" ";
        //}
        //cout<<endl;
    //}
    // butterfly pattern
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"* ";
        }
        int space=2*n-2*(i+1);
        for(int j=0;j<n-2*(i+1);j++){
            cout<<"  ";
        }
        for(int j=0;j<i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}