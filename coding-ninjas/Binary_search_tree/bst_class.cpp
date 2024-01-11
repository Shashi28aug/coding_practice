Implement all following function

1. insert
2. search 
3. delete 
4. printTree (recursive)
    n:L:x, R:y


class BST {
    BinaryTreeNode<int> *root;
   public:
    BST() { 
        root = NULL;
    }

	private:
    BinaryTreeNode<int>* maximum(BinaryTreeNode<int> *root){
        if(root == NULL){
            return NULL;
        }
        
        
        
        
        
    }
    BinaryTreeNode<int>* removeHelper(BinaryTreeNode<int> *root, int data){
        if(root == NULL)
            return root;
        
        if(root->data > data){
            return removeHelper(root->left, data);
        }else if(root->data < data){
            return removeHelper(root->right, data);
        }else{
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }else if(root->left == NULL){
                return root->right;
            }else if(root->right == NULL){
                return root->left;
            }else{
                BinaryTreeNode<int>* maxNode = root->right;
                while(maxNode->left != NULL){
                    maxNode = maxNode->left;
                }
                int temp = root->data;
                root->data = maxNode->data;
                maxNode->data = temp;
                root->right = removeHelper(maxNode, data);
                return root;
            }
        }
    }
    public:
    void remove(int data) {  
        root = removeHelper(root, data);
    }
	private:
    void printHelper(BinaryTreeNode<int> *root){
        if(root == NULL)
            return;
        cout << root->data <<':';
        if(root->left != NULL)
            cout << "L:" << root->left->data<<',';
        if(root->right != NULL)
            cout << "R:" << root->right->data;
        cout << endl;
        printHelper(root->left);
        printHelper(root->right);   
    }
    public:
    void print() { 
       printHelper(root);
    }
    
    private:
    BinaryTreeNode<int>* insertHelper(BinaryTreeNode<int> *root, int data){
        if(root == NULL){
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }
        
        if(root->data >= data){
            if(root->left == NULL){
               	BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
                root->left = node;
            }else
            	BinaryTreeNode<int> *node = insertHelper(root->left, data);
            
        }else{
            if(root->right == NULL){
                BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
                root->right = node;
            }else
            	BinaryTreeNode<int> *node = insertHelper(root->right, data);
        }
        
        return root;
    }
	public:
    void insert(int data) { 
        root = insertHelper(root, data);
    }
    
    private:
    bool searchHelper(BinaryTreeNode<int> *root, int data){
        if(root == NULL){
            return false;
        }
        
        if(root->data == data){
            return true;
        }
        
        if(root->data > data){
            return searchHelper(root->left, data);
        }else
            return searchHelper(root->right, data);
        
    }
	public:
    bool search(int data) {
        return searchHelper(root, data);
    }
};
