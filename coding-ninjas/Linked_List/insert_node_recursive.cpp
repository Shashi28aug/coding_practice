#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

Node *insert_node(Node *head, int pos, int data) {
    if(head == NULL)
        return head;
    if(pos == 0) {
        Node *temp = new Node(data);
        temp -> next = head;
        head = temp;
        return head;
    }

    head -> next =  insert_node(head->next, pos-1, data);

    return head;
}

int main() {
    Node *head = NULL;
    int n;
    cin >> n;
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
    int pos, data;
    cin >> pos >> data;
    head = insert_node(head, pos, data);
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}