#include<iostream>
using namespace std;

class Node{
        public:
           int data;
           Node* next;

           Node(int val){
               data = val;
               next = NULL;
           }
};

void insertAtTail(Node* &head,int val){
    
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;

}

Node* reverse(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next= prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//recursive way

Node* reverseRecursive(Node* &head){
//base case
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

int main(){
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    //display(head);
    //insertAtHead(head,6);
    display(head);
    //Node* newhead = reverse(head);
    //display(newhead);
    Node* newhead = reverseRecursive(head);
    display(newhead);
    //cout<<search(head,10)<<endl;
    return 0;
}