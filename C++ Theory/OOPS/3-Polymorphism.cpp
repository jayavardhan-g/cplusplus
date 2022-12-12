#include <bits/stdc++.h>
using namespace std;
class functionoverload{
    int lmao;
    int mao;
    int ao;
    public:
    void overload(){
        lmao=0;
        mao=0;
        ao=0;
    }
    void overload(int a){
        lmao=a;
        mao=a;
        ao=a;
    }
    void overload(double a){
        lmao=a* 10;
    }
};


int main(){
    //function overload
    functionoverload a;
    a.overload(3);
}