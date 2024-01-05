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

class minMax {
    public:
        int minValue;
        int maxValue;
};

minMax findMinMax(BinaryTreeNode<int> *root) {
    if(root == NULL){
        minMax result;
        result.maxValue = INT_MIN;
        result.minValue = INT_MAX;
        
        return result;
    }

    minMax result;

    minMax leftResult = findMinMax(root->left);
    minMax rightResult = findMinMax(root->right);

    result.maxValue = max(root->data, max(leftResult.maxValue, rightResult.maxValue));
    result.minValue = min(root->data, min(leftResult.minValue, rightResult.minValue));

    return result;

}

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

int main () {
    BinaryTreeNode<int> *root = inputLevelWise();
    minMax result = findMinMax(root);
    cout << result.minValue << " ";
    cout << result.maxValue << endl;

}