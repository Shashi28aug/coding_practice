#include <iostream>

using namespace std;

int main () {

}

class largestBST {
    public:
        int minElem;
        int maxElem;
        bool isBST;
        int heightBST;
} 

BinaryTreeNode *largestTree (BinaryTreeNode *root) {
    if(root == NULL) {
        largestBST result;
        result.minElem = INT_MAX;
        result.maxElem = INT_MIN;
        result.isBST = true;
        result.heightBST = 0;

        return result;
    }

    largestBST leftResult = largestTree(root->left);
    largestBST rightResult = largestTree(root->right);
    largestBST result;

    result.minElem = min(root->data, min(leftResult.minElem, rightResult.minElem));
    result.maxElem = max(root->data, max(leftResult.maxElem, rightResult.maxElem));
    result.isBST = (root->data > leftResult.maxElem && root->data <= rightResult.minElem)&&(leftResult.isBST && rightResult.isBST);

    if(result.BST)
        result.heightBST = 1 + max(leftResult.heightBST, rightResult.heightBST);
    else
        result.heightBST = max(leftResult.heightBST, rightResult.heightBST);

    return result;
}