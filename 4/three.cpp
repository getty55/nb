#include <iostream>
#include <vector>

template<typename T>
struct LinkedList{
    T data;
    LinkedList<T>* next;
    LinkedList(T d) : data{d}, next{nullptr} {}
};

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
    TreeNode* root = new TreeNode(9);
    root->setLeftChild(new TreeNode(11));
    root->setRightChild(new TreeNode(5));
    root->getLeft()->setLeftChild(new TreeNode(7));
    root->getLeft()->setRightChild(new TreeNode(6));
    root->getRight()->setLeftChild(new TreeNode(23));
    root->getRight()->setRightChild(new TreeNode(19));
    return root;
}

std::vector<LinkedList<int>*> createLists(TreeNode* root){
    std::vector<LinkedList<int>*> result;
    LinkedList<int>* current;
    LinkedList<TreeNode*>* curr;
    auto c = curr;
    
    if (root){
        current = new LinkedList<int>(root->getData());
        curr = new LinkedList<TreeNode*>(root); //std::cout << curr->data->getData() << '\n';        
    }

    while (curr->data){
        result.push_back(current);
        c = curr;
        LinkedList<TreeNode*>* parents = c; //std::cout << "pa " << parents->data->getData() << '\n';
        curr = nullptr; //if (!curr) std::cout << "empty\n";
        current = nullptr;
        
        if (parents->data->getLeft()){ std::cout << "pal " << parents->data->getData() << '\n';
            current = new LinkedList<int>(parents->data->getLeft()->getData());
            //current = current->next;
            curr = new LinkedList<TreeNode*>(parents->data->getLeft()); //std::cout << "l " << curr->data->getData() << '\n';
            //if (curr->next) curr = curr->next;
        }
        if (parents->data->getRight()){ std::cout << "par " << parents->data->getData() << '\n';
            current = new LinkedList<int>(parents->data->getRight()->getData());
            //current = current->next;
            curr = new LinkedList<TreeNode*>(parents->data->getRight()); //std::cout << "r " << curr->data->getData() << '\n';
            //if (curr->next) curr = curr->next;
        }
        if (!parents->data->getLeft() && !parents->data->getRight()){
            //current = new LinkedList<int>(pa)
            std::cout << "h\n";
            curr->data = nullptr;
        }
    }
    return result;
}

int main(){
    auto t = createTree();
    auto a = createLists(t);
    //std::cout << a.size() << '\n';
    /*for (auto aa : a) {
        while (aa){
            std::cout << aa->data << " ";
            aa = aa->next;
        }
        std::cout << '\n';
    }*/
}
