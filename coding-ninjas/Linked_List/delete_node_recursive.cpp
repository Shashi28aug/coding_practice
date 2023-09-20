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

Node *delete_node(Node *head, int pos) {
    if(head == NULL)
        return head;
    if(pos == 0) {
        Node *temp = head->next;
        delete(head);
        return temp;
    }

    head -> next =  delete_node(head->next, pos-1);

    return head;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
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
        int pos;
        cin >> pos;
        head = delete_node(head, pos);
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
}