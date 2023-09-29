#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode (T data) {
            this->data = data;
        }

        ~TreeNode () {
            for(int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }

};

int sumOfNodes (TreeNode<int> *root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    int sum = 0;
    while (!pendingNodes.empty()) {
        TreeNode<int>* frontNode = pendingNodes.front();
        sum += frontNode->data;
        pendingNodes.pop();
        for(int i = 0; i < frontNode->children.size(); i++) {
            pendingNodes.push(frontNode->children[i]);
        }
    }
    return sum;
}

TreeNode<int> *inputLevelWise () {
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
            frontNode->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }

    return root;
    
}

int main () {
    TreeNode<int> *root = inputLevelWise();
    cout << sumOfNodes(root);
}