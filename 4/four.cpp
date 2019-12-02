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
    TreeNode* root = new TreeNode(1);
    root->setLeftChild(new TreeNode(2));
    root->setRightChild(new TreeNode(2));
    root->getLeft()->setLeftChild(new TreeNode(3));
    root->getLeft()->setRightChild(new TreeNode(3));
    /*root->getLeft()->getLeft()->setLeftChild(new TreeNode(4));
    root->getLeft()->getLeft()->setRightChild(new TreeNode(4));*/
    return root;
}

bool balanced(TreeNode* root){
    if (root->getLeft() && !root->getRight()){
        root = root->getLeft();
        if (root->getLeft() || root->getRight()) return false;
        return true;
    }
    else if (root->getRight() && !root->getLeft()){
        root = root->getRight();
        if (root->getLeft() || root->getRight()) return false;
        return true;
    }
    else if (root->getLeft() && root->getRight()){
        return balanced(root->getLeft()) && balanced(root->getRight());
    }
    return false;
}

int main(){
    TreeNode* t = createTree();
    if (balanced(t)) std::cout << "balanced\n";
    else std::cout << "not balanced\n";
}