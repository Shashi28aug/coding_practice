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

    Node *rev = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rev;
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