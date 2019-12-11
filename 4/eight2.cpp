#include <iostream>

class TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
  public:
    TreeNode(int d) : data{d} {}
    void setLeftChild(TreeNode* l){ this->left = l; };
    void setRightChild(TreeNode* r){ this->right = r; };

    int getData() const{ return data; }
    TreeNode* getLeft() const{ return left; }
    TreeNode* getRight() const{ return right; }
};

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

bool covers(TreeNode* root, TreeNode* p){
    if (!root) return false;
    if (root == p) return true;
    return covers(root->getLeft(), p) || covers(root->getRight(), p);
}

TreeNode* ancestorHelper(TreeNode* root, TreeNode* p, TreeNode* q){
    if (!root || root == p || root == q) return root;
    bool pIsOnLeft = covers(root->getLeft(), p);
    bool qIsOnLeft = covers(root->getLeft(), q); 
    if (pIsOnLeft != qIsOnLeft) return root;
    TreeNode* childSide = pIsOnLeft ? root->getLeft() : root->getRight();
    return ancestorHelper(childSide, p, q);
}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (!covers(root, p) || !covers(root, q)) return nullptr;
    return ancestorHelper(root, p, q);
}

int main(){
    TreeNode* t = createTree();
    auto p = t->getRight()->getLeft();
    auto q = t->getRight()->getRight();
    auto a = commonAncestor(t, p, q);
    std::cout << "the first common ancestor of "
              << p->getData() << " and " << q->getData() << " is: " << a->getData() << '\n';
}