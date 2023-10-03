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

int countX(TreeNode<int> *root, int x) {
    if(root == NULL)
        return 0;
    
    int res = 0;
    if(root->data > x)
        res = 1;
    for(int i = 0; i < root->childrens.size(); i++) {
        res += countX(root->childrens[i], x);
    }

    return res;
}

int main () {
    TreeNode<int> *root = inputLevelWise();
    int x;
    cin >> x;
    cout << countX(root, x);
}