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

void delete_node(Node *head, int i) {
    if(head == NULL)
        return;
    if(i == 0){
        Node *temp = head;
        head = head->next;
        delete(temp);
        return;
    }

    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL) {
        if(i == 0) {
            prev -> next = curr -> next;
            delete(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
        i--;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Node *head = NULL;
        Node *temp = head;
        while(n != -1) {
            if(temp == NULL) {
                temp = new Node(n);
                head = temp;
            }else {
                temp->next = new Node(n);
                temp = temp->next;
            }
            cin >> n;
        }
        int i;
        cin >> i;
        delete_node(head, i);
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
}