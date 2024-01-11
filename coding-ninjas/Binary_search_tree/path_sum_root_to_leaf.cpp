void pathSumHelper(BinaryTreeNode *root, int k,  string path) {
    if(root == NULL)
        return;
    if(k == 0) {
        cout << path << endl;
        return;
    }
    if(k < 0)
        return;
    if(root->left == NULL && root->right == NULL) {
        if(k == root->data) {
            path = path + root->data + " ";
            cout << path << endl;
        }
        else
            return;
    }
    if(root->left)
        pathSumHelper(root->left, k-root->data, path+root->data+" ");
    if(root->right)
        pathSumHelper(root->right, k-root->data, path+root->data+" ")
}
void pathSum(BinaryTreeNode *root, int k) {
    pathSumHelper(root, k, "");
}