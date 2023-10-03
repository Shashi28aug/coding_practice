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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    if(root1->childrens.size() != root2->childrens.size())
        return false;
    
    bool res = false;
    if(root1->data == root2->data)
        return true;
    for(int i = 0; i < root1->childrens.size(); i++) {
        res = res && isIdentical(root1->childrens[i], root2->childrens[i]);
    }

    return res;
}

int main () {
    TreeNode<int> *root1 = inputLevelWise();
    TreeNode<int> *root2 = inputLevelWise();
    cout << (isIdentical(root1, root2) ? "true" : "false");
}