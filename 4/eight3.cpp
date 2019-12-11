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

struct Result{
    TreeNode* node;
    bool isAncestor;
    Result(TreeNode* n, bool ia) : node{n}, isAncestor{ia} {}
};

Result ancestorHelper(TreeNode* root, TreeNode* p, TreeNode* q){
    if (!root) return Result(nullptr, false);
    if (root == p && root == q) return Result(root, true);
    
    Result rx = ancestorHelper(root->getLeft(), p, q);
    if (rx.isAncestor) return rx;

    Result ry = ancestorHelper(root->getRight(), p, q);
    if (ry.isAncestor) return ry;

    if (rx.node && ry.node) return Result(root, true);
    else if (root == p || root == q){
        bool isAnc = rx.node != nullptr || ry.node != nullptr;
        return Result(root, isAnc);
    }
    else return Result(rx.node != nullptr ? rx.node : ry.node, false);
}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    Result r = ancestorHelper(root, p, q);
    if (r.isAncestor) return r.node;
    return nullptr;
}

int main(){
    TreeNode* t = createTree();
    auto p = t->getRight()->getLeft();
    auto q = t->getRight()->getRight();
    auto a = commonAncestor(t, p, q);
    std::cout << "the first common ancestor of "
              << p->getData() << " and " << q->getData() << " is: " << a->getData() << '\n';
}