#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main(){
    int n;cin>>n;
    cout<< ~n<<endl;

    /*
        2s compliment of a n = -n
        2s compliment = 1s compliment + 1
        1s compliment = 2s compliment - 1

        So,
        1s compliment (n) = 2s compliment(n) - 1
        1s compliment (n) = (-n) - 1
        1s compliment (n) = -(n+1)
    */
    
    unsigned int l= n;
    cout<< ~l;
}