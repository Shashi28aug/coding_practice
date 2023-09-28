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

class Stack {
    Node *head;
    int size;

    public:
        Stack () {
            head = NULL;
            size = 0;
        }

        void push (int data) {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
            size++;
            return;
        }

        int pop () {
            if(size == 0)
                return -1;
            Node *temp = head;
            head = head->next;
            int element = temp->data;
            delete temp;
            size--;
            return element;
        }

        int top () {
            if(size == 0)
                return -1;
            return head->data;
        }

        int getSize () {
            return size;
        }

        bool isEmpty () {
            if(size == 0)
                return true;
            else
                return false;
        }


};

int main() {
    int q;
    cin >> q;
    Stack stack;
    while (q--) {
        int x, data;
        cin >> x;
        
        switch (x) {
            case 1:
                cin >> data;
                stack.push(data);
                break;
            case 2:
                cout << stack.pop() << endl;
                break;
            case 3:
                cout << stack.top() << endl;
                break;
            case 4:
                cout << stack.getSize() << endl;
                break;
            default:
                cout << (stack.isEmpty() ? "true\n" : "false\n");
                break;
        }
    }
}