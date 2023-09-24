#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

Node *reverse(Node *head) {
    if(head == NULL || head->next ==  NULL)
        return head;

    Node *prev, *curr;
    prev = NULL;
    curr = head;

    while (curr != NULL) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
    
    return head;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Node *head = NULL;
        Node *temp = NULL;
        while (n != -1) {
            if(head == NULL) {
                temp = new Node(n);
                head = temp;
            }else {
                temp->next = new Node(n);
                temp = temp->next;
            }
            cin >> n;
        }
        Node *result = reverse(head);
        while (result != NULL) {
            cout << result->data << " ";
            result = result ->next;
        }
    }
}