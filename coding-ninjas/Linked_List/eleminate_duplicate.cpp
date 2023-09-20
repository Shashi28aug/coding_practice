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

Node* eliminate_duplicate(Node *head) {
    if(head == NULL || head -> next == NULL)
        return head;

   Node *temp = head;
   while (temp->next != NULL) {
        if(temp->data == temp->next->data) {
            Node *t = temp->next;
            temp->next = temp->next->next;
            delete t;
        }else {
            temp = temp->next;
        }
   }
   
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
        head = eliminate_duplicate(head);
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        
    }
}