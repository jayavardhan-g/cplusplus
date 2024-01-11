#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// Polymorphism = multiple forms
// 1. Compile time polymorphism
// 2. Runtime polymorphism

// Compile time -> The various types of that method there are

// Runtime polymorphism -> 1. Same name 2. Same parameters 3. Through inheritance only

class Hero{
    public:
    int a=4;

    void operator< (Hero & b){
        cout<<a<<"Hello"<<endl;
    }
};

int32_t main(){
    Hero a,b;
    a<b;
}