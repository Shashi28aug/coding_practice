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

int find_node(Node *head, int data) {
    if(head == NULL)
        return -1;
    if(head->data == data)
        return 0;
    int res = find_node(head->next, data);
    return res == -1 ? -1 : res+1;
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
        int data;
        cin >> data;
        cout << find_node(head, data);
    }
}