int lcaBinaryTree(BinaryTreeNode<int> *root, int a, int b) {
    if(root == NULL) 
        return -1;
    if(root->data == a || root->data == b)
        return root->data;
    
    int left = lcaBinaryTree(root->left, a, b);
    int right = lcaBinaryTree(root->right, a, b);
    if(left != -1 && right != -1)
        return root->data;
    if(left == -1)
        return right;
    if(right == -1)
        return left;

    return -1;
}