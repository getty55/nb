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
    root->setLeftChild(new TreeNode(3));
    root->setRightChild(new TreeNode(7));
    /*root->getLeft()->setLeftChild(new TreeNode(7));
    root->getLeft()->setRightChild(new TreeNode(4));
    root->getRight()->setLeftChild(new TreeNode(9));
    root->getRight()->setRightChild(new TreeNode(6));*/
    return root;
}

void DFSMakeLists(TreeNode* root, std::vector<std::list<TreeNode*>*>& lists, int level){
    if (!root) return;
    std::list<TreeNode*>* list;
    if (lists.size() == level){
        std::cout<<"hh\n";
        list = new std::list<TreeNode*>();
        lists.push_back(list); 
    }
    else {
        std::cout << "h\n";
        list = lists[level];    
    }

    list->push_back(root);
    DFSMakeLists(root->getLeft(), lists, level+1);
    DFSMakeLists(root->getRight(), lists, level+1);
}

int main(){
    TreeNode* t = createTree();
    std::vector<std::list<TreeNode*>*> lists;
    DFSMakeLists(t, lists, 0);
    for (auto aa : lists){
        for (std::list<TreeNode*>::iterator it = aa->begin(); it != aa->end(); ++it) 
            std::cout << (*it)->getData() << " ";
        std::cout << '\n';
    }
}