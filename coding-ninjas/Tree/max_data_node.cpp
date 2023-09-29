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

TreeNode<int>* maxDataNode(TreeNode<int> *root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    TreeNode<int> *maxDataNode = root;
    while (!pendingNodes.empty()) {
        TreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        if(maxDataNode->data < frontNode->data) {
                maxDataNode = frontNode;
            }
        for(int i = 0; i < frontNode->childrens.size(); i++) {
            pendingNodes.push(frontNode->childrens[i]);
        }
    }
    return maxDataNode;
}

int main () {
 TreeNode<int> *root = inputLevelWise();
 cout << maxDataNode(root)->data;
}