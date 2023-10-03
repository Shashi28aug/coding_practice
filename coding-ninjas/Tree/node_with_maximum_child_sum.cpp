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

        ~TreeNode () {
            for(int i = 0; i < childrens.size(); i++) {
                delete childrens[i];
            }
        }
    
};

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
        while (numChild--){
            int data;
            cin >> data;
            TreeNode<int>* child = new TreeNode<int>(data);
            frontNode->childrens.push_back(child);
            pendingNodes.push(child);
        } 
    }
    return root; 
}

TreeNode<int>* nodeMaxSum(TreeNode<int> *root) {
    if(root == NULL)
        return root;
    
    TreeNode<int> *maxNode = root;
    int sum = root->data;
    for(int i = 0; i < root->childrens.size(); i++) {
        sum += root->childrens[i]->data;
    }
    
    for(int i = 0; i < root->childrens.size(); i++) {
        TreeNode<int> *child = nodeMaxSum(root->childrens[i]);
        int childSum = child->data;
        for(int j = 0; j < child->childrens.size(); j++) {
            childSum += child->childrens[j]->data;
        }
        if(sum < childSum) {
            sum = childSum;
            maxNode = child;
        }
    }

    return maxNode;
}

int main () {
    TreeNode<int> *root = inputLevelWise();
    cout << nodeMaxSum(root)->data;
}