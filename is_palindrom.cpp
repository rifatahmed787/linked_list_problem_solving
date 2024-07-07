#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node*& head, int v) {
    Node* newNode = new Node(v);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* reverse_copy(Node* head) {
    Node* newHead = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* newNode = new Node(temp->val);
        newNode->next = newHead;
        newHead = newNode;
        temp = temp->next;
    }
    return newHead;
}

bool is_palindrome(Node* head) {
    if (head == NULL) return true;
    Node* reversedHead = reverse_copy(head);

    Node* temp = head;
    Node* reverseTemp = reversedHead;
    
    while (temp != NULL) {
        if (temp->val != reverseTemp->val) {
            return false;
        }
        temp = temp->next;
        reverseTemp = reverseTemp->next;
    }
    return true;
}


int main() {
    Node* head = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert_at_tail(head, val);
    }

    if (is_palindrome(head)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
