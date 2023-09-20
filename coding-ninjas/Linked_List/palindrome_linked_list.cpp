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

Node *reverse(Node *head) {
    if(head == NULL || head->next != NULL)
        return head;
    
    Node *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    head = temp;
    return head;
}

bool palindrome(Node *head) {
    if(head == NULL)
        return true;

    Node *head2 = NULL;
    Node *temp = head;
    Node *temp2 = head2;
    while(temp != NULL){
    	Node *t = new Node(temp->data);
        if(head2 == NULL){
            head2 = t;
            temp2 = head2;
        }else{
            temp2->next = t;
            temp2 = temp2->next;
        }
        
        temp = temp->next;
    }

    head2 = reverse(head2);

    while (head != NULL) {
        if(head->data != head2->data)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    
    return true;
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
        if(palindrome(head))
            cout << "true";
        else
            cout << "false";
    }
}