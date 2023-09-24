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

Node *evenOdd(Node *head) {
    if(head == NULL || head->next ==  NULL)
        return head;

    Node *even = NULL;
    Node *odd = NULL;
    
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    
    while(head != NULL){
        Node *t = new Node(head->data);
        if(head->data%2 == 0){
            if(even == NULL){
                even = t;
                temp1 = even;
            }else{
                temp1->next = t;
                temp1 = temp1->next;
            }
        }else{
            if(odd == NULL){
                odd = t;
                temp2 = odd;
            }else{
                temp2->next = t;
                temp2 = temp2->next;
            }
        }
        
        head = head->next;
    }
    
    if(odd == NULL){
        head = even;
    }else{
        temp2->next = even;
	    head = odd;
    }
    
    return head;
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
        Node *result = evenOdd(head);
        while (result != NULL) {
            cout << result->data << " ";
            result = result ->next;
        }
    }
}