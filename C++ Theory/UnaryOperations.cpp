#include <bits/stdc++.h>
using namespace std;
int main(){
    int i=0,j=1;
    // 0   1   0     1       2     3    
    i= i + j + i++ + j++ + ++i + ++j;
    cout<<i;
    i=0;
    //  0       0     1   1     0    -1
    j = i++ - --i + ++i - i-- - i-- - i--;
    cout<<endl<<i<<endl<<j;
    i=10;j=20; int k;
    //10    9       19    9   19     10  18 
    k=i-- - i++ + --j + --i - j-- + ++i - j++;
    cout<<endl<<j<<endl<<i<<endl<<k;
}