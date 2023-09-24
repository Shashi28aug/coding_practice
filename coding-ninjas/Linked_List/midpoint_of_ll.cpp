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

Node *midpoint(Node *head) {
    if(head == NULL)
        return head;

    Node *ptr = head;
    Node *ptr2 = head;
    while(ptr2->next != NULL && ptr2->next->next != NULL) {
        ptr = ptr->next;
        ptr2 = ptr2->next->next;
    }

    return ptr;
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
        Node *result = midpoint(head);
        if(result)
            cout << result->data;
        else
            cout << -1;
        
    }
}