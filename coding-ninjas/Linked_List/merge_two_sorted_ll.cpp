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

Node *merge(Node *head1, Node *head2) {
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    Node *resultHead = NULL;
    Node *resultTail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data <= head2->data) {
            if(resultHead == NULL) {
                resultHead = head1;
                resultTail = head1;
                head1 = head1->next;
            } else {
                resultTail->next = head1;
                resultTail = head1;
                head1 = head1->next;
            }
        }else {
            if(resultHead == NULL) {
                resultHead = head2;
                resultTail = head2;
                head2 = head2->next;
            } else {
                resultTail->next = head2;
                resultTail = head2;
                head2 = head2->next;
            }
        }
    }

    if(head1 == NULL)
        resultTail->next = head2;
    if(head2 == NULL)
        resultTail->next = head1;

    return resultHead;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Node *head1 = NULL;
        Node *temp = NULL;
        while (n != -1) {
            if(head1 == NULL) {
                temp = new Node(n);
                head1 = temp;
            }else {
                temp->next = new Node(n);
                temp = temp->next;
            }
            cin >> n;
        }
        cin >> n;
        Node *head2 = NULL;
        temp = NULL;
        while (n != -1) {
            if(head2 == NULL) {
                temp = new Node(n);
                head2 = temp;
            }else {
                temp->next = new Node(n);
                temp = temp->next;
            }
            cin >> n;
        }
        Node *result = merge(head1, head2);
        while (result != NULL) {
            cout << result->data << " ";
            result = result ->next;
        }
        
    }
}