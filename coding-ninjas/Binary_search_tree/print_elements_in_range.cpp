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

void printElementsInRange (BinaryTreeNode<int> *root, int k1, int k2) {
    if(root == NULL)
        return;
    if(root->data >= k1)
    	printElementsInRange(root->left, k1, k2);
    if(root->data >= k1 && root->data <= k2)
        cout << root->data << ' ';
    if(root->data <= k2)
    	printElementsInRange(root->right, k1, k2);
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
    int k1, k2;
    cin >> k1 >> k2;
    printElementsInRange(root, k1, k2);

}