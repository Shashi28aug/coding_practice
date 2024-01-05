#include <iostream>
#include <queue>
#include <climits>

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

pair<bool, int> checkBalanced(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        pair<bool, int> result;
        result.first = true;
        result.second = 0;
        return result;
    }

    pair<bool, int> result;

    pair<bool, int> leftResult = checkBalanced(root->left);
    pair<bool, int> rightResult = checkBalanced(root->right);

    result.first = (leftResult.first && rightResult.first) && (abs(leftResult.second - rightResult.second) <= 1);
    result.second = 1+max(leftResult.second, rightResult.second);

    return result;
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    cout << (checkBalanced(root).first ? "true" : "false");

}