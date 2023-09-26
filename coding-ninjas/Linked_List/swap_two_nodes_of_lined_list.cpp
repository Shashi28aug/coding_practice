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

Node *swapNodes(Node *head, int i, int j)
{
    if(head == NULL)
        return head;
    if(i == j)
        return head;
    
    int ci = 0;
    int cj = 0;
    Node *temp = head;
    Node *in = head;
    Node *jn = head;
    
    while(temp != NULL){
        if(ci == i-1){
            in = temp;
        }
        
        if(cj == j-1){
            jn = temp;
        }
        ci++;
        cj++;
        temp = temp->next;
    }
    
    Node *jnext = jn->next;
    Node *inext = in->next;
    
    in->next = jnext;
    jn->next = inext;
    
    Node *t = inext->next;
    inext->next = jnext->next;
    jnext->next = t;
    
    
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
        int i, j;
        cin >> i >> j;
        Node *result = swapNodes(head, i, j);
        while (result != NULL) {
            cout << result->data << " ";
            result = result ->next;
        }
    }
}