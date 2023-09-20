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

Node* append_last(Node *head, int pos) {
    if(head == NULL || pos == 0)
        return head;

    Node *temp = head;
    int len = 0;
    
    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }
    
    Node *temp2 = head;
    int i = len-pos;
    while(temp2 != NULL && i > 0){
        temp2 = temp2->next;
        i--;
    }
    
    temp->next = head;
    head = temp2->next;
    temp2->next = NULL;
    
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
        head = append_last(head, pos);
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        
    }
}