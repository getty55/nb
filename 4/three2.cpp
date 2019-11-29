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
    left = l;
    if (l) l->parent = this;
}

void TreeNode::setRightChild(TreeNode* r){
    right = r;
    if (r) r->parent = this;
}

TreeNode* createTree(){
    TreeNode* root = new TreeNode(9);
    root->setLeftChild(new TreeNode(11));
    root->setRightChild(new TreeNode(5));
    root->getLeft()->setLeftChild(new TreeNode(7));
    root->getLeft()->setRightChild(new TreeNode(6));
    root->getRight()->setLeftChild(new TreeNode(23));
    root->getRight()->setRightChild(new TreeNode(19));
    return root;
}

std::vector<std::list<int>> createList(TreeNode* root){
    std::vector<std::list<int>> result;
    std::list<int> current;
    std::list<TreeNode*> curr;

    if (root){
        current.push_back(root->getData());
        curr.push_back(root);
    }

    while (curr.size() > 0){
        result.push_back(current);
        std::list<TreeNode*> parents = curr;
        curr.clear();
        current.clear();
        for (TreeNode* parent : parents){
            if (parent->getLeft()){
                current.push_back(parent->getLeft()->getData());
                curr.push_back(parent->getLeft());
            }
            if (parent->getRight()){
                current.push_back(parent->getRight()->getData());
                curr.push_back(parent->getRight());
            }
        }
    }
    return result;
}

int main(){
    TreeNode* t = createTree();
    std::vector<std::list<int>> a = createList(t);
    for (auto aa : a){
        for (std::list<int>::iterator it = aa.begin(); it != aa.end(); ++it) std::cout << *it << " ";
        std::cout << '\n';
    }
}