#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode (T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

int binarySearch(int k, int *arr, int s, int e) {
    if(s > e)
        return -1;
    int m = (s+e)/2;
    if(arr[m] == k)
        return m;
    if(arr[m] < k)
        return binarySearch(k, arr, m+1, e);
    if(arr[m] > k)
        return binarySearch(k, arr, s, m-1);
    return -1;
}

BinaryTreeNode<int> *buildTreeHelper(int *preorder, int *inorder, int preS, int preE, int inS, int inE) {
    
    if(inS > inE)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preS]);
    int rootIndex = binarySearch(preorder[preS], inorder, inS, inE);

    root->left = buildTreeHelper(preorder, inorder, preS+1, preS+(rootIndex-inS), inS, rootIndex-1);
    root->right = buildTreeHelper(preorder, inorder, preS+(rootIndex-inS)+1, preE, rootIndex+1, inE);

    return root;

}

BinaryTreeNode<int> *buildTree(int n, int *preorder, int *inorder) {
    if(n == 0)
        return NULL;
    if(n == 1)
        return new BinaryTreeNode<int>(preorder[0]);

    return buildTreeHelper(preorder, inorder, 0, n-1, 0, n-1);
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

int main () {
    int n;
    cin >> n;
    int *preorder = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    int *inorder = new int[n];
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }

    BinaryTreeNode<int> *root = buildTree(n, preorder, inorder);

    printLevelWise(root);
}