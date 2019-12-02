#include <iostream>
#include <cmath>
#include <limits>

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

int checkHeight(TreeNode* root){
    if (!root) return -1;
    int leftHeight = checkHeight(root->getLeft());
    if (leftHeight == std::numeric_limits<int>::min()) return std::numeric_limits<int>::min();
    int rightHeight = checkHeight(root->getRight());
    if (rightHeight == std::numeric_limits<int>::min()) return std::numeric_limits<int>::min();

    int heightDiff = leftHeight-rightHeight;
    if (std::abs(heightDiff) > 1) return std::numeric_limits<int>::min();
    return std::max(leftHeight, rightHeight)+1;
}

bool balanced(TreeNode* root){
    return checkHeight(root) != std::numeric_limits<int>::min();
}

int main(){
    TreeNode* t = createTree();
    if (balanced(t)) std::cout << "balanced\n";
    else std::cout << "not balanced\n";
}