int lcaBst(BinaryTreeNode<int> *root, int a, int b) {
    if(root == NULL)
        return -1;
    if(root->data == a || root->data == b)
        return root->data;
    
    if((a <= root->data && root->data < b) || (a >= root->data && root->data > b))
        return root->data;

    if(root->data >= a && root->data >= b)
        return lcaBst(root->left, a, b);
    if(root->data <= a && root->data <= b)
        return lcaBst(root->right, a, b)

    return -1;
    
}