#include <iostream>
#include <vector>
#include <list>

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
    TreeNode* root = new TreeNode(8);
    root->setLeftChild(new TreeNode(5));
    root->setRightChild(new TreeNode(2));
    root->getLeft()->setLeftChild(new TreeNode(7));
    root->getLeft()->setRightChild(new TreeNode(4));
    root->getRight()->setLeftChild(new TreeNode(9));
    root->getRight()->setRightChild(new TreeNode(6));
    return root;
}

std::vector<std::list<TreeNode*>> makeLists(TreeNode* root){
    std::vector<std::list<TreeNode*>> result;
    std::list<TreeNode*> curr;
    if (root) curr.push_back(root);

    while (!curr.empty()){
        result.push_back(curr);
        auto parents = curr;
        curr.clear();
        for (auto parent : parents){
            if (parent->getLeft()) curr.push_back(parent->getLeft());
            if (parent->getRight()) curr.push_back(parent->getRight());
        }
    }
    return result;
}

int main(){
    TreeNode* t = createTree();
    auto a = makeLists(t);
    for (auto aa : a){
        for (std::list<TreeNode*>::iterator it = aa.begin(); it != aa.end(); ++it){
            std::cout << (*it)->getData() << " ";
        }
        std::cout << '\n';
    }
}