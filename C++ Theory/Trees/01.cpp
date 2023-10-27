//Traversal
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};

//Pre-order root left right
void preorder(Node* node){
    if(node==NULL)return;
    cout<<node->val<<' ';
    preorder(node->left);
    preorder(node->right);
}
//In-order left root right
void inorder(Node* node){
    if(node==NULL)return;
    inorder(node->left);
    cout<<node->val<<' ';
    inorder(node->right);
}
//Post-order left right root
void postorder(Node* node){
    if(node==NULL)return;
    postorder(node->right);
    postorder(node->left);
    cout<<node->val<<' ';
}

//BFS (level wise)

void levelorder(Node* node){
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node *t= q.front();
        q.pop();
        cout<<t->val<<' ';
        if(t->left)q.push(t->left);
        if(t->right)q.push(t->right);
    }
    cout<<endl;
}

int32_t main(){
    Node* s= new Node(1);
    s->left= new Node(2);
    s->right = new Node(3);
    s->left->left= new Node(4);
    s->left->right= new Node(5);
    s->left->right->left= new Node(6);
    s->right->left=new Node(7);
    s->right->right=new Node(8);
    s->right->right->left=new Node(9);
    s->right->right->right=new Node(10);
    levelorder(s);
    preorder(s);
}