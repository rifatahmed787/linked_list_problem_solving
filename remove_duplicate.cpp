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
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int size(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void sort_the_val(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *dupli = temp;
        while (dupli->next != NULL)
        {
        }
    }
}

void remove_duplicate(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->val == temp->next->val)
        {
            Node *duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void remove_duplicate_2(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        Node *dupli = temp;
        while (dupli->next != NULL)
        {
            if (dupli->next->val == temp->val)
            {
                Node *duplicateNode = dupli->next;
                dupli->next = dupli->next->next;
                delete duplicateNode;
            }
            else
            {
                dupli = dupli->next;
            }
        }
        temp = temp->next;
    }
}

void remove_after_sort(Node *head)
{

    for (int i = 0; i < size(head) - 1; i++)
    {
        Node *current = head;
        Node *next = head->next;

        for (int j = 0; j < size(head) - 1 - i; j++)
        {
            if(current->val > next->val){
                swap(current->val, next->val);
            }
            current = next;
            next=next->next;
        }
    }

    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->val == temp->next->val)
        {
            Node *duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        }
        else
        {
            temp = temp->next;
        }
    }
   
}

void print_node(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

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

    // remove_duplicate(head);
    // remove_duplicate_2(head);
    remove_after_sort(head);
    print_node(head);

    return 0;
}