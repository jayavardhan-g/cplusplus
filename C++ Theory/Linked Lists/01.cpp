#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtStart(Node* &head,int value){
    Node* temp=new Node(value);
    temp->next = head;
    head=temp;
}

void insertAtEnd(Node *&head,int value){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newnode= new Node(value);
    temp->next=newnode;
}

void insertInMiddle(Node*&head, int position,int value){
    Node*ptr=head;
    for(int i=1;i<position;i++){
        ptr=ptr->next;
    }
    Node * temp= new Node(value);
    temp->next= ptr->next;
    ptr->next=temp;
}

void deleteNodePosition(Node* &head, int position){
    Node* ptr=head;
    for(int i=1;i<position;i++){
        ptr=ptr->next;
    }
    ptr->next= ptr->next->next;
}

void deleteNodeValue(Node* &head,int value){
    Node*ptr=head;
    while(ptr->next!=NULL && ptr->next->data!=value){
        ptr=ptr->next;
    }
    
    if(ptr->next!=NULL)ptr->next= ptr->next->next;

}

void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}

int32_t main(){
    Node *head= NULL;
    insertAtStart(head,3);
    insertAtStart(head,2);
    insertAtStart(head,1);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    insertInMiddle(head,3,100);
    deleteNodePosition(head,3);
    deleteNodeValue(head,1);
    printList(head);
}