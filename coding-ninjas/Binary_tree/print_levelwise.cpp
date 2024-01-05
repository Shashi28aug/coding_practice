#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode (T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode () {
            delete left;
            delete right;
        }

};

BinaryTreeNode<int> *inputLevelWise () {
    int data;
    cin >> data;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            pendingNodes.push(leftChild);
            frontNode->left = leftChild;
        }
       
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            pendingNodes.push(rightChild);
            frontNode->right = rightChild;
        }
    }
    return root;
}

void printLevelWise (BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty()) {
        BinaryTreeNode<int> *frontNode = pendingNode.front();
        pendingNode.pop();
        cout << frontNode->data << ":";
        if(frontNode->left) {
            pendingNode.push(frontNode->left);
            cout << "L:" << frontNode->left->data << ",";
        }else {
            cout << "L:-1,";
        }
        if(frontNode->right) {
            pendingNode.push(frontNode->right);
            cout << "R:" << frontNode->right->data << endl;
        }else {
             cout << "R:-1" << endl;
        }
    }
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    printLevelWise(root);
}