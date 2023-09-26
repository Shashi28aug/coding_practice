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

Node *bubbleSort(Node *head)
{
    if(head == NULL)
        return head;
    
    int size = 0;
    Node *temp = head;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    int n = size-1;
  
    while(n--){
        Node* prev =NULL;
        Node*cur = head;
        while(cur->next!=NULL){
            if(cur->data >=cur->next->data){
                // Swap
                if(prev==NULL){
                    //first node
                    Node* nxt = cur->next ;
                    cur->next = nxt->next ;
                    nxt->next = cur ;
                    prev=nxt ;
                    head = prev ;
                }else{
                    Node* nxt = cur->next ;
                    prev->next = nxt ;
                    cur->next = nxt->next ;
                    nxt->next = cur ;
                    prev = nxt ;
                }
            }else{
                prev = cur ; 
                cur=cur->next ;
            }
        }
	}
   
    return head ;
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
        Node *result = bubbleSort(head);
        while (result != NULL) {
            cout << result->data << " ";
            result = result ->next;
        }
    }
}