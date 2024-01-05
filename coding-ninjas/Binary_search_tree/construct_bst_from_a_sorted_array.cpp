BinaryTreeNode<int> *constructTree(int *arr, int s, int e) {
    if(s > e)
        return NULL;
    
    int m = (s+e)/2;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[m]);
    root->left = constructTree(arr, s, m-1);
    root->right = constructTree(arr, m+1, e);

    return root;
}