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

Node *deleteEveryN(Node *head, int n, int m) {
    if(head == NULL)
        return head;
    if(n == 0)
        return NULL;
    if(m == 0)
        return head;

    Node *t1  = head;
    Node *t2 = head;
    
    while (t1 != NULL && t2 != NULL) {

        int c1 = 1, c2 = 1;
        while (t1 != NULL && c1 != m) {
            t1 = t1->next;
            c1++;
        }
        if(t1 == NULL)
            return head;
        
        t2 = t1->next;
        while (t2 != NULL && c2 != n) {
            Node *temp = t2;
            t2 = t2->next;
            c2++;
            delete temp;
        }
        t1->next = t2;
        if(t2 == NULL)
            return head;
        
        Node *temp = t2;
        t1->next = t2->next;
        t1 = t2->next;
        t2 = t2->next;
        delete temp;
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
        int a, b;
        cin >> a >> b;
        Node *result = deleteEveryN(head, a, b);
        while (result != NULL) {
            cout << result->data << " ";
            result = result ->next;
        }
    }
}