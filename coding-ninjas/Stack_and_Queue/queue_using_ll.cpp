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

class Queue {
    Node *head;
    Node *tail;
    int size;

    public:
        Queue () {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void enqueue (int data) {
            if(head && tail){
                head = new Node(data);
                tail = head;
            }
            else {
                tail->next = new Node(data);
                tail = tail->next;
            }
            size++;
            return;
        }

        int dequeue () {
            if(size == 0)
                return -1;
            Node *temp = head;
            head = head->next;
            int element = temp->data;
            delete temp;
            size--;
            if(size == 0)
                tail = NULL;
            return element;
        }

        int front () {
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
    Queue queue;
    while (q--) {
        int x, data;
        cin >> x;
        
        switch (x) {
            case 1:
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                cout << queue.dequeue() << endl;
                break;
            case 3:
                cout << queue.front() << endl;
                break;
            case 4:
                cout << queue.getSize() << endl;
                break;
            default:
                cout << (queue.isEmpty() ? "true\n" : "false\n");
                break;
        }
    }
}