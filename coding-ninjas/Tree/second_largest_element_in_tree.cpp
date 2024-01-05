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

class elem {
    public:
        TreeNode<int> *lar;
        TreeNode<int> *slar;
};

elem secLargest (TreeNode<int> *root) {
    if(root == NULL) {
        elem res;
        res.slar = NULL;
        res.lar = NULL;
        return res;
    }

    elem res;
    res.lar = root;
    res.slar = NULL;

    for(int i = 0; i < root->childrens.size(); i++) {
        elem child = secLargest(root->childrens[i]);
        if(child.lar->data > res.lar->data){
            TreeNode<int> * temp = res.lar;
            res.lar = child.lar;
            if(child.slar != NULL && child.slar->data > temp->data ){
                res.slar = child.slar;
            }else
                res.slar = temp;
        }else if(child.lar->data < res.lar->data){
            if(res.slar != NULL && res.slar->data < child.lar->data){
             	res.slar = child.lar;   
            }else if(res.slar == NULL){
                res.slar = child.lar; 
            }
        }
    }
    return res;
}

int main () {
    TreeNode<int> *root = inputLevelWise();
    cout << secLargest(root).slar->data;
}