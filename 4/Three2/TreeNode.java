import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Iterator;

public class TreeNode{
    public int data;
    public TreeNode left;
    public TreeNode right;
    public TreeNode parent;
    private int size = 0;

    public TreeNode(int d){
        data = d;
        size = 1;
    }

    private void setLeftChild(TreeNode left){
        this.left = left;
        if (left != null) left.parent = this;
    }

    private void setRightChild(TreeNode right){
        this.right = right;
        if (right != null) right.parent = this;
    }

    public void insertInOrder(int d){
        if (d <= data){
            if (left == null) setRightChild(new TreeNode(d));
            else left.insertInOrder(d);
        }
        else {
            if (right == null) setRightChild(new TreeNode(d));
            else right.insertInOrder(d);
        }
        size++;
    }

    public int size(){ return size; }

    public boolean isBST(){
        if (left != null){
            if (data < left.data || !left.isBST()) return false;
        }
        if (right != null){
            if (data >= right.data || right.isBST()) return false;
        }
        return true;
    }

    public int height(){
        int leftHeight = left != null ? left.height() : 0;
        int rightHeight = right != null ? right.height() : 0;
        return 1+Math.max(leftHeight, rightHeight);
    }

    public TreeNode find(int d){
        if (d == data) return this;
        else if (d <= data) return left != null ? left.find(d) : null;
        else if (d > data) return right != null ? right.find(d) : null;
        return null;
    }

    public void print(){
        BTreePrinter.printNode(this);
    }

    public static TreeNode createTree(){
        TreeNode root = new TreeNode(9);
    
        root.setLeftChild(new TreeNode(11));
        root.setRightChild(new TreeNode(5));
        root.left.setLeftChild(new TreeNode(7));
        root.left.setRightChild(new TreeNode(6));
        root.right.setLeftChild(new TreeNode(23));
        root.right.setRightChild(new TreeNode(19));
        return root;
    }
    
    public static ArrayList<LinkedList<Integer>> createList(TreeNode root){
        ArrayList<LinkedList<Integer>> result = new ArrayList<LinkedList<Integer>>();
        LinkedList<Integer> current = new LinkedList<Integer>();
        LinkedList<TreeNode> curr = new LinkedList<TreeNode>();

        if (root != null){
            current.add(root.data);
            curr.add(root);
        }

        while (curr.size() > 0){
            result.add(current);
            LinkedList<TreeNode> parents = curr;
            curr = new LinkedList<TreeNode>();
            current = new LinkedList<Integer>();
            for (TreeNode parent : parents){
                if (parent.left != null){
                    current.add(parent.left.data);
                    curr.add(parent.left);
                }
                if (parent.right != null){
                    current.add(parent.right.data);
                    curr.add(parent.right);
                }
            }
        }
        return result;
    }

    public static void main(String[] args){
        TreeNode t = createTree();
        t.print();
        ArrayList<LinkedList<Integer>> a = createList(t);
        for (LinkedList<Integer> aa : a){
            for (Iterator i = aa.iterator(); i.hasNext(); ){
                System.out.print(i.next() + " ");
            }
            System.out.println();
        }
        
    }
}