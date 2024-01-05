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

TreeNode<int>* nextLarger(TreeNode<int> *root, int x) {
    if(root == NULL)
        return root;
    
    TreeNode<int> *secondMaxNode = root;
    if(root->data > x)
        secondMaxNode = root;
    
    for(int i = 0; i < root->childrens.size(); i++) {
        TreeNode<int> *child = nextLarger(root->childrens[i], x);
        if(child != NULL && secondMaxNode != NULL && child->data < secondMaxNode->data)
            secondMaxNode = child;
        else if(secondMaxNode == NULL && child != NULL)
            secondMaxNode = child;
    }

    return secondMaxNode;
}

int main () {
    TreeNode<int> *root = inputLevelWise();
    int x;
    cin >> x;
    cout << nextLarger(root, x)->data;
}