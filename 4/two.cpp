#include <iostream>
#include <vector>

class TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int size;
  public:
    TreeNode(int d) : data{d}, size{1} {}
    
    void setLeftChild(TreeNode*);
    void setRightChild(TreeNode*);
    void insertInOrder(int);
    bool isBST();
    int height();
    TreeNode* find(int);

    int getSize() const{ return size; }
    int getData() const{ return data; }
};

void TreeNode::setLeftChild(TreeNode* l){
    this->left = l;
    if (l) l->parent = this;
}

void TreeNode::setRightChild(TreeNode* r){
    this->right = r;
    if (r) r->parent = this;
}

void TreeNode::insertInOrder(int d){
    if (d <= data){
        if (!left) setLeftChild(new TreeNode(d));
        else left->insertInOrder(d);
    }
    else {
        if (!right) setRightChild(new TreeNode(d));
        else right->insertInOrder(d);
    }
    ++size;
}

bool TreeNode::isBST(){
    if (left)
        if (data < left->data || !left->isBST()) return false;
    if (right)
        if (data >= right->data || !right->isBST()) return false;
    return true;
}

int TreeNode::height(){
    int leftHeight = left != nullptr ? left->height() : 0;
    int rightHeight = right != nullptr ? right->height() : 0;
    return 1+(leftHeight > rightHeight ? leftHeight : rightHeight);
}

TreeNode* TreeNode::find(int d){
    if (d == data) return this;
    else if (d <= data) return left != nullptr ? left->find(d) : nullptr;
    else if (d > data) return right != nullptr ? right->find(d) : nullptr;
    return nullptr;
}

TreeNode* createMinimalBST(std::vector<int>& v, int start, int end){
    if (end < start) return nullptr;
    int mid = (start+end)/2;
    TreeNode* n = new TreeNode(v[mid]);
    n->setLeftChild(createMinimalBST(v, start, mid-1));
    n->setRightChild(createMinimalBST(v, mid+1, end));
    return n;
}

TreeNode* createMinimalBST(std::vector<int>& v){
    return createMinimalBST(v, 0, v.size()-1);
}

int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    TreeNode* root = createMinimalBST(v, 0, v.size()-1);
    std::cout << "Root? " << root->getData() << '\n';
    std::cout << "Created BST? " << root->isBST() << '\n';
    std::cout << "Height? " << root->height() << '\n';
}