#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode (T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

BinaryTreeNode<int> *inputLevelWise(){
    int data;
    cin >> data;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        int leftData, rightData;
        cin >> leftData >> rightData;
        if(leftData != -1) {
            frontNode->left = new BinaryTreeNode<int>(leftData);
            pendingNodes.push(frontNode->left);
        }
        if(rightData != -1) {
            frontNode->right = new BinaryTreeNode<int>(rightData);
            pendingNodes.push(frontNode->right);
        }
    }
    return root;
}

template <typename T>
class Node {
    public:
        T data;
        Node *next;
        Node (T data) {
            this->data = data;
            next = NULL;
        }
};

vector<Node<int> *> levelWiseList(BinaryTreeNode<int> *root) {
    vector<Node<int> *> result;
    if(root == NULL)
        result;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL){
            if(pendingNodes.empty()){
                break;
            }
            result.push_back(head);
            head = NULL;
            tail = NULL;
            pendingNodes.push(NULL);
            continue;

        }
        if(head == NULL) {
            head = new Node<int>(front->data);
            tail = head;
        }else {
            tail->next = new Node<int>(front->data);
            tail = tail->next;
        }

        if(front->left)
            pendingNodes.push(front->left);
        if(front->right)
            pendingNodes.push(front->right);
    }

    return result;
    
}

void printList(vector<Node<int>*> list) {
    for(int i = 0; i < list.size(); i++) {
        Node<int> *head = list[i];
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
        
    }
    
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    vector<Node<int> *> list = levelWiseList(root);
    printList(list);
}