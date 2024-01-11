#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// Instance of class is an object
// Static members can exist without creating an object
// this -> is not used in static functions
// static functions can only access static members

// public,private,protected - access modifiers

//Classes are basically data types and we can define how they behave

class Hero{
    // public:
    static int time;
    public:
    void set(int t){
        time=t;
    }
    void print(){
        cout<<time<<endl;
    }
};

int Hero::time = 4;

int32_t main(){
    Hero b,c,d;
    b.print();
    c.print();
    d.print();

    b.set(5);
    b.print();
    c.print();
    d.print();
    c.set(18);
    b.print();
    c.print();
    d.print();


}