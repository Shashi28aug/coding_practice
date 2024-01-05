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

bool findNode (BinaryTreeNode<int> *root, int x) {
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;
    return (findNode(root->left, x) || findNode(root->right, x));
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    int x;
    cin >> x;
    cout << (findNode(root, x) ? "true" : "false");
}