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

void print(Node *head, int i) {
    while (head != NULL)
    {
        if(i-1 == 0){
            cout << head->data;
            break;
        }
        head = head->next;
        i--;
    }  
}

int main() {
    int t;
    cin >> t;
    while(t--){
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
        int i;
        cin >> i;
        print(head, i);
    }
}