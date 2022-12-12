#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int sort[5];
    for (int i=0;i<5;i++){int x;cin >>x; sort[i]=x;};
    int i=0;
    int n;
    
    for (int x=0; x<3; x++){
        for (int l=0; l<4; l++){
            if(sort[l]>sort[l+1]){
                int m=sort[l];
                sort[l]=sort[l+1];
                sort[l+1]=m;
            }else {};
        }
    }
    

    // Printing 
    for (int i=0;i<5;i++){cout << sort[i]<<"   ";}
}
