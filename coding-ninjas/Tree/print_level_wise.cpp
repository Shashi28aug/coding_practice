#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T> *> childrens;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for(int i = 0; i <childrens.size(); i++) {
                delete childrens[i];
            }
        }
};

TreeNode<int> *takeInputLevelWise () {
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        TreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        while (numChild--) {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            frontNode -> childrens.push_back(child);
            pendingNodes.push(child);
        }     
    }
    return root;                                                                                                                                                                             
}

void printLevelWise (TreeNode<int> *root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        TreeNode<int> *frontNode = pendingNodes.front();
        cout << frontNode->data << ":";
        vector<TreeNode<int>*> childrens= frontNode->childrens;
        for (int i = 0; i < childrens.size(); i++) {
            TreeNode<int> *child = childrens[i];
            cout << child->data << ",";
            pendingNodes.push(child);
        }
        pendingNodes.pop();
        cout << endl; 
    }
    
}

int main () {
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
}