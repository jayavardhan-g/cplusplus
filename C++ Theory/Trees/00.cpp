#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

class Node{
public:
int data;
Node* left;
Node* right;
Node(int v){
    data=v;
    left=NULL;
    right=NULL;
}
};

int32_t main(){
    Node* root=new Node(1);
    // New node of data 1 and both left and right branches NULL is formed
    root->left  = new Node(2);
    // 1-> 2
    root->right = new Node(3);
    // 2<- 1 ->3
    root->left->left= new Node(4);
    // 4<-2<-1->3
}