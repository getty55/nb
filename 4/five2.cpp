#include <iostream>

class TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
  public:
    TreeNode(int d) : data{d} {}
    void setLeftChild(TreeNode*);
    void setRightChild(TreeNode*);
    int getData() const{ return data; }
    TreeNode* getLeft() const{ return left; }
    TreeNode* getRight() const{ return right; }
};

void TreeNode::setLeftChild(TreeNode* l){
    this->left = l;
    if (l) l->parent = this;
}

void TreeNode::setRightChild(TreeNode* r){
    this->right = r;
    if (r) r->parent = this;
}

TreeNode* createTree(){
    TreeNode* root = new TreeNode(10);
    root->setLeftChild(new TreeNode(5));
    root->getLeft()->setLeftChild(new TreeNode(1));
    root->getLeft()->setRightChild(new TreeNode(100));
    /*root->getRight()->setLeftChild(new TreeNode(6));
    root->getRight()->setRightChild(new TreeNode(8));*/
    return root;
}

bool validateBST(TreeNode* root){
    if (root->getLeft() && root->getRight()){
        if (root->getLeft()->getData() > root->getData() || root->getRight()->getData() < root->getData()) return false;
        return validateBST(root->getLeft()) && validateBST(root->getRight());
    }    
    if (root->getLeft() && !root->getRight()){
        if (root->getLeft()->getData() > root->getData()) return false;
        return validateBST(root->getLeft());
    }
    if (root->getRight() && !root->getLeft()){
        if (root->getRight()->getData() < root->getData()) return false;
        return validateBST(root->getRight());
    }
    return true;
}

int main(){
    TreeNode* t = createTree();
    if (validateBST(t)) std::cout << "valid BST\n";
    else std::cout << "not a BST\n";
}