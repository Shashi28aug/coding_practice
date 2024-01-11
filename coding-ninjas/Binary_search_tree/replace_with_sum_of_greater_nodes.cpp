int sumOfGreaterNode(BinaryTreeNode *root, int sum) {
    if(root == NULL)
        return 0;
    
    int rightSum = sumOfGreaterNode(root->right , sum);
    int temp = root->data;
    root->data = root->data + rightSum + sum;
    int leftSum = sumOfGreaterNode(root->left, root->data);

    return temp+rightSum+leftSum;
    
}
BinaryTreeNode *replacewithsum(BinaryTreeNode *root) {
    sumOfGreaterNode(root, 0);
}