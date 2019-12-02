#include <iostream>
#include <cmath>

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
    TreeNode* root = new TreeNode(1);
    root->setLeftChild(new TreeNode(2));
    root->setRightChild(new TreeNode(6));
    root->getLeft()->setLeftChild(new TreeNode(3));
    root->getRight()->setRightChild(new TreeNode(3));
    root->getLeft()->getLeft()->setLeftChild(new TreeNode(4));
    root->getRight()->getRight()->setRightChild(new TreeNode(4));
    return root;
}

int getHeight(TreeNode* root){
    if (!root) return -1;
    return std::max(getHeight(root->getLeft()), getHeight(root->getRight()))+1;
}

bool balanced(TreeNode* root){
    if (!root) return true;
    int heightDiff = getHeight(root->getLeft())-getHeight(root->getRight());
    if (std::abs(heightDiff) > 1){
        std::cout << root->getData() << '\n';
        return false;
    }
    else return balanced(root->getLeft()) && balanced(root->getRight());
}

int main(){
    TreeNode* t = createTree();
    if (balanced(t)) std::cout << "balanced\n";
    else std::cout << "not balanced\n";
}