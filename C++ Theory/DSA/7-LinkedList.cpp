#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int value;
    node* link;
    node(int v){
        value=v;
        link=NULL;
    }
};

void addatend(node* &head, int v){
    node* n=new node(v);
    node*temp=head;
    if(head==NULL){
        head=n;
        return;
    }
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=n;
}

void addatstart(node* &head, int v){
    node *n=new node(v);
    n->link=head;
    head=n;
}

void printlinkedlist(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->link;
    }
    cout<<endl;
}
void insertinbetween(node *head, int p,int v){
    node *n=new node(v);
    node*temp=head;
    for(int i=1;i<p-1;i++){
        temp=temp->link;
    }
    n->link=temp->link;
    temp->link=n;
}
int search(node * head, int v){
    node*temp=head;
    int i=0;
    while(temp!=NULL){
        i++;
        if(temp->value==v)return i;
        temp=temp->link;
    }
    return -1;
}
void deletenode(node* &head, int v ){
    node* temp=head;
    while(temp->link->value!=v){
        temp=temp->link;
        if(temp->link==NULL)return;
    }
    node* todelete=temp->link;
    temp->link=temp->link->link;
    delete todelete;
}

int main(){
    node* head=NULL;
    addatend(head, 12);
    addatend(head, 10);
    addatend(head, 4);
    addatend(head, 15);
    addatstart(head, 13);
    insertinbetween(head, 3,3);
    cout<<search(head,3);
    deletenode(head, 3);
    printlinkedlist(head);
    cout<<search(head,3);
}