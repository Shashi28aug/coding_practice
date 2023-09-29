#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> childrens;

        TreeNode (T data) {
            this->data = data;
        }
        ~TreeNode() {
            for(int i = 0; i < childrens.size(); i++) {
                delete childrens[i];
            }
        }
};

TreeNode<int>* inputLevelWise () {
    int data;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        TreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        while (numChild--) {
            int data;
            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data);
            frontNode->childrens.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int countLeaf(TreeNode<int> *root) {
    if(root == NULL)
        return 0;
    if(root->childrens.size() == 0)
        return 1;

    int count = 0;
    for(int i = 0; i < root->childrens.size(); i++) {
        count += countLeaf(root->childrens[i]);
    }
    return count;
}

int main () {
 TreeNode<int> *root = inputLevelWise();
 cout << countLeaf(root);
}