vector<int> *findPath(BinaryTreeNode<int> *root, int k) {
    if(root == NULL)
        return NULL;
    if(root->data == k) {
        vector<int> *ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }

    vector<int> *leftAns = findPath(root->left);
    if(leftAns->size()) {
        leftAns->push_back(root->data);
        return leftAns;
    }

    vector<int> *rightAns = findPath(root->right);
    if(rightAns->size()) {
        rightAns->push_back(root->data);
        return rightAns;
    }

    return NULL;
}