void printNodeDepthK (BinaryTreeNode *root, int k){
    if(root == NULL || k < 0)
        return;
    
    if(k == 0){
        cout << root->data << endl;
    	return;
    }
    
    printNodeDepthK(root->left, k-1);
    printNodeDepthK(root->right, k-1);
    
}

int nodesAtDistanceKHelper (BinaryTreeNode *root, int node, int k) {
    if(root == NULL) {
        return  -1;
    }
    if(root->data == node) {
        printNodeDepthK(root, k);
        return 0;
    }

    int ld = nodesAtDistanceKHelper(root->left, node , k);
    if(ld! = -1) {
        if(ld+1 == k) {
            cout << root->data << endl;
        }else {
            printNodeDepthK(root->right, k-(ld+1)-1);
        }
        return ld+1;
    }else {
        int rd = nodesAtDistanceKHelper(root->right, node, k);
        if(rd != -1){
            if(rd+1 == k) {
                cout << root->data << endl;
            }else {
                printNodeDepthK(root->left, k-(rd+1)-1);
            }
            return rd+1;
        }else
            return -1;
    }
}
void nodesAtDistanceK (BinaryTreeNode *root, int node, int k) {
    nodesAtDistanceKHelper(root, node, k);
}