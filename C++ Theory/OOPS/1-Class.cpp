#include <bits/stdc++.h>
using namespace std;
//declaring a class
class person{
    int password;
    string crush;
    public:
    string name;        //data member 
    int age;        //data member
    string gender;      //data member
    
    void knowcrush(){
        cout<<crush<<"- This is his crush"<<endl;
    }
    void setcrush(){
        cin>>crush;
    }
};
class student{
    string name;
    int standard;
    public:
    //default constructor
    student(){
        name="default";
        standard=0;
    };
    //parameterised constructor
    student(string str, int s){
        name=str;
        standard=s;
    }
    void printinfo(){
        cout<<"Name: "<<name;
        cout<<"Class: "<<standard;
    } 
    //destructor 
    ~student(){
        cout<<"Object "<<name<<" is destroyed"<<endl;
    }
    bool operator == (student &a){
        if(name==a.name)return true;
        return false;
    }
};
int main(){
    // person p1,p2,p3; //objects of the class person 
    // p1.name="Jay"; 
    // p1.age=20; 
    // p1.setcrush();
    // p1.knowcrush();
    student l;
    student n("nani",30); 
    n.printinfo();
    student m=n; 
    student p(n);
    m.printinfo();
    student k("nani", 7);
    if(k==n)cout<<"Both are equal"<<endl;

}