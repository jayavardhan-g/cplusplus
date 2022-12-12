#include <iostream>
using namespace std;
const int N=3;
class stack{
    public:
    int *arr=new int[N];
    int top;
    stack(){
        top=-1;
    }
    stack(int a){
        top=0;
        arr[top]=a;
    }
    void push(int a){
        if(top==N-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=a;
    }
    void pop(){
        if(top==-1){cout<<"The stack is empty"<<endl;return;}
    }
    int Top(){
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};
int main(){
    stack l(20);
    l.pop();
    l.push(20);
    cout<<l.Top()<<endl;
    l.push(30);
    l.push(30);
    l.push(30);
    cout<<l.Top()<<endl;
    cout<<l.empty()<<endl;

}
