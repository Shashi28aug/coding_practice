#include <iostream>
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
        }
};

bool searchInBST (BinaryTreeNode<int> *root, int x) {
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;
    if(root->data > x)
        return searchInBST(root->left, x);
    return searchInBST(root->right, x);
}

BinaryTreeNode<int> *inputLevelWise () {
    int data;
    cin >> data;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (data);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
        cin >> leftData >> rightData;
        if(leftData != -1) {
            front->left = new BinaryTreeNode<int>(leftData);
            pendingNodes.push(front->left);
        }
        if(rightData != -1) {
            front->right = new BinaryTreeNode<int>(rightData);
            pendingNodes.push(front->right);
        }
    }
    return root;
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    int x;
    cin >> x;
    cout << (searchInBST(root, x) ? "true" : "false");

}