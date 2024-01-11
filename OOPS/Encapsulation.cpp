#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// Encapsulation is the method of wrapping datamembers and functions 
// Full encapsulation is when all the data members are private
// Uses - Data hiding, Make the class read-only, Code reusability

class Hero{
    int a,b;
    public:
    int c;

};

// Single inheritance A->B
class Child : public Hero{

};

//Multilevel inheritance A->B->C
class Her:public Hero{

};
class He:public Her{

};

// Multiple inheritance  A,B->C
class Super: public Hero, private He{

};

//Hierarchichal inheritance  A-> B,C
class B:public Hero{

};
class C:private Hero{

};

// Inheritance ambiguity
// when there are similar functions in both the parents eg.abc() then we don't write
// obj.abc(); instead we write
// obj.A::abc(); or obj.B::abc();


int32_t main(){
    
}