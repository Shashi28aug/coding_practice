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
    pendingNode.push(NULL);
    while (!pendingNode.empty()) {
        BinaryTreeNode<int> *first = pendingNode.front();
        pendingNode.pop();
        if (first == NULL) {
            if (pendingNode.empty()) {
                break;
            }
            cout << endl;
            pendingNode.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            pendingNode.push(first->left);
        }
        if (first->right != NULL) {
            pendingNode.push(first->right);
        }
    }
}


BinaryTreeNode<int>* mirror (BinaryTreeNode<int> *root) {
    if(root == NULL)
        return root;
    
    BinaryTreeNode<int> *leftRes = mirror(root->left);
    BinaryTreeNode<int> *rightRes = mirror(root->right);
    root->left = rightRes;
    root->right = leftRes;

    return root;
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    printLevelWise(mirror(root));
}