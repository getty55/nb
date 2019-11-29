#include <iostream>
#include <vector>
#include <list>

template<typename T>
class TreeNode{
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
  public:
    TreeNode(T d) : data{d} {}
    void setLeftChild(TreeNode*);
    void setRightChild(TreeNode*);
    T getData() const{ return data; }
    TreeNode* getLeft() const{ return left; }
    TreeNode* getRight() const{ return right; }
};

template<typename T>
void TreeNode<T>::setLeftChild(TreeNode* l){
    this->left = l;
    if (l) l->parent = this;
}

template<typename T>
void TreeNode<T>::setRightChild(TreeNode* r){
    this->right = r;
    if (r) r->parent = this;
}


TreeNode<int>* createTree(){
    TreeNode<int>* root = new TreeNode<int>(8);
    root->setLeftChild(new TreeNode<int>(5));
    root->setRightChild(new TreeNode<int>(2));
    root->getLeft()->setLeftChild(new TreeNode<int>(7));
    root->getLeft()->setRightChild(new TreeNode<int>(4));
    root->getRight()->setLeftChild(new TreeNode<int>(9));
    root->getRight()->setRightChild(new TreeNode<int>(6));
    return root;
}

std::vector<std::list<TreeNode<int>*>> makeLists(TreeNode<int>* root){
    std::vector<std::list<TreeNode<int>*>> result;
    std::list<TreeNode<int>*> curr;

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
    TreeNode<int>* t = createTree();
    auto a = makeLists(t);
    for (auto aa : a){
        for (std::list<TreeNode<int>*>::iterator it = aa.begin(); it != aa.end(); ++it) std::cout << (*it)->getData() << " ";
        std::cout << '\n';
    }
}