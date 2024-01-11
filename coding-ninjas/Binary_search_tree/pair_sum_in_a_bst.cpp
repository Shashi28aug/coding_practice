void pairSumHelper(BinaryTreeNode *root, int *arr, int *pos) {
    if(root == NULL)
        return;

    pairSumHelper(root->left, arr, pos);
    arr[(*pos)] = root->data;
    (*pos)++;
    pairSumHelper(root->right, arr, pos);
}

void printNodeSumtoS(BinaryTreeNode *root) {
    if(root == NULL) {
        return;
    }

    int *arr = new int[10000];
    int size = 0;
    pairSumHelper(root, arr, &size);

    int i = 0;
    int j = size-1;

    while(i > j) {
        if(arr[i]+arr[j] == s) {
            cout << arr[i] << '' << arr[j] << endl;
            i++;
            j--;
        }else if(arr[i]+arr[j] > s) {
            j--;
        }else {
            i++;
        }
    }
}