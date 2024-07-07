#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next=NULL;

   Node(int val){
    this->val=val;
    this->next=NULL;
   }
};


int size(Node *head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}


void insert_at_tail(Node *&head, int v)
{

    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        return;
    };
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    
};

void print_middle(Node *head){
     Node *temp = head;
     int sz=size(head);

    for(int i=0; i<sz/2; i++){
        temp=temp->next;
    }
    cout<<temp->val;
}

int main(){
    Node* head = NULL;
    int val;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        insert_at_tail(head, val);
    }
    
    print_middle(head);
  
    return 0;
}