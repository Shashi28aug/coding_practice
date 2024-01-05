#include <iostream>
#include <queue>
#include <stack>

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

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
	
    if(root->left != NULL && root->right == NULL){
        cout << root->left->data << ' ';
    }else if(root->left == NULL && root->right != NULL){
        cout << root->right->data << ' ';
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
    
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    printNodesWithoutSibling(root);
}