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

int length(Node *head) {
    if(head == NULL)
        return 0;
    int count = 0;
    while (head != NULL)
    {
       head = head->next;
       count++;
    }
    return count;
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
        cout << length(head);
}