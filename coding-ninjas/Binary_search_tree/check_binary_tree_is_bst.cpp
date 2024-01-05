pair<pair<int, int>, bool> isBST(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        pair<pair<int, int>, bool> ans;
        ans.first.first = INT_MIN;
        ans.first.second = INT_MAX;
        ans.second = true;

        return ans;
    }

    pair<pair<int, int>, bool> leftAns = isBST(root->left);
    pair<pair<int, int>, bool> rightAns = isBST(root->right);

    pair<pair<int, int>, bool> ans;

    ans.fist.first = max(ans.first.first, max(leftAns.first.first, rightAns.first.first));
    ans.fist.second = max(ans.first.second, max(leftAns.first.second, rightAns.first.second));

    ans.second = (root->data >= leftAns.first.first) && (root->data <= leftAns.first.second) && leftAns.second && rightAns.second;

    return ans;
}