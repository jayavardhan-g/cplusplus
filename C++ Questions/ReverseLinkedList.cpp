#include<bits/stdc++.h>
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
void reverselist(node* &head){
    node* previous=NULL;
    node* current=head;
    node* next;
    
    while(next!=NULL){
        next=current->link;
        current->link=previous;
        previous=current; 
        current=next;

    }
    head=previous;

}

node* recursive(node* &h){
    node* head;
    if(h->link==NULL){
        head=h->link;
    }
    


    return head;
}

int main(){
    node* h=NULL;
    int n;
    cin>>n;
    for(n;n>0;n--){
        int l;
        cin>>l;
        addatend(h,l);
    }
    printlinkedlist(h);
    // reverselist(h);
    node*l=recursive(h);

    printlinkedlist(l);
}