#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next = NULL;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = newNode;
   
}

bool print_detect_cycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
};
int main()
{
    Node *head = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, val);
    }

    if (print_detect_cycle(head))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}