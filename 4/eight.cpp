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
    TreeNode* getParent() const{ return parent; }
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
    TreeNode* root = new TreeNode(3);
    root->setLeftChild(new TreeNode(5));
    root->setRightChild(new TreeNode(1));
    root->getLeft()->setLeftChild(new TreeNode(6));
    root->getLeft()->setRightChild(new TreeNode(2));
    root->getLeft()->getRight()->setLeftChild(new TreeNode(7));
    root->getLeft()->getRight()->setRightChild(new TreeNode(4));
    root->getRight()->setLeftChild(new TreeNode(0));
    root->getRight()->setRightChild(new TreeNode(8));
    return root;
}

int depth(TreeNode* node){
    int depth = 0;
    while (node){
        node = node->getParent();
        ++depth;
    }
    return depth;
}

TreeNode* goUpBy(TreeNode* node, int delta){
    while (delta > 0 && node){
        node = node->getParent();
        delta;
    }
    return node;
}

TreeNode* commonAncestor(TreeNode* p, TreeNode* q){
    int delta = depth(p)-depth(q);
    TreeNode* first = delta > 0 ? q : p;
    TreeNode* second = delta > 0 ? p : q;
    second = goUpBy(second, std::abs(delta));

    while (first != second && first && second){
        first = first->getParent();
        second = second->getParent();
    }
    return first == nullptr || second == nullptr ? nullptr : first;
}

int main(){
    TreeNode* t = createTree();
    auto p = t->getRight()->getLeft();
    auto q = t->getRight()->getRight();
    auto a = commonAncestor(p, q);
    std::cout << "the first common ancestor of "
              << p->getData() << " and " << q->getData() << " is: " << a->getData() << '\n';
}