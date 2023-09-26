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

class Pair {
    public:
        Node *head;
        Node *tail;
};

Pair reverse(Node *head, Node *tail) {
    if(head == NULL || head->next == NULL){
        Pair reversePair;
        reversePair.head = head;
        reversePair.tail = head;
        return reversePair;
    }

    Pair reversePair = reverse(head->next, tail);
    head->next->next = head;
    head->next = NULL;
    reversePair.tail = head;
    
    return reversePair;
}

Node *kReverse(Node *head, int k)
{
    if(head == NULL || k == 0 || k == 1)
        return head;

    Node *head1 = head, *tail = head;
    int c = 1;
    while (head1->next != NULL && c < k) {
        head1 = head1->next;
        tail = head1;
        c++;
    }
    Node *head2 = tail->next;
    tail->next = NULL;

    Pair reversePair = reverse(head, tail);

    head2 = kReverse(head2, k);

    reversePair.tail->next = head2;

    return reversePair.head;
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
        int k;
        cin >> k;
        Node *result = kReverse(head, k);
        while (result != NULL) {
            cout << result->data << " ";
            result = result ->next;
        }
    }
}