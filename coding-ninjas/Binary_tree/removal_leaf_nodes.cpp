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

void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front == NULL){
            if(pendingNodes.empty()){
                break;
            }
            cout << endl;
            pendingNodes.push(NULL);
            continue;

        }
        cout << front->data << " ";

        if(front->left)
            pendingNodes.push(front->left);
        if(front->right)
            pendingNodes.push(front->right);
    }
    
}

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return NULL;
    
    if(root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    root =  removeLeafNodes(root);
    printLevelWise(root);
}