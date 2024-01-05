void bstToListHelper(BinaryTreeNode<int> *root, Node<int> *head) {
    if(root == NULL)
        return;

    bstToListHelper(root->left, head)
    if(head == NULL)
        head = new Node<int>(root->data);
    else
        head->next = new Node<int>(root->data);
    bstToListHelper(root->right, head);
}

Node<int> *bstToList(BinaryTreeNode<int> *root) {
    Node<int> *head = NULL;
    bstToListHelper(root, head);

    return head;
}