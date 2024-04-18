public class Recursive
{

    static class BstNode
    {
        int data;
        BstNode lefBstNode;
        BstNode righBstNode;
    }

    static class BstTree
    {
        BstNode root;
        BstTree()
        {
            root = null;
        } 

        public void Insert(int data, BstNode r)
        {
            if(root == null)
            {
                BstNode t = new BstNode();
                t.data = data;
                t.lefBstNode = t.righBstNode = null;
                root = t;
            }

            else if(r.data > data)
            {
                if (r.lefBstNode == null) 
                {
                    BstNode t = new BstNode();
                    t.data = data;
                    r.lefBstNode = t;
                    t.lefBstNode = t.righBstNode = null;
                }
                else
                {
                    Insert(data, r.lefBstNode);
                }
            }
            else
            {
                if (r.righBstNode == null) {
                    BstNode t = new BstNode();
                    t.data = data;
                    r.righBstNode = t;
                    t.lefBstNode = t.righBstNode = null;
                }
                else
                {
                    Insert(data, r.righBstNode);
                }
            }
        }

        public void wrapperInsert(int data)
        {
            Insert(data, root);
        }

        void inOrder(BstNode currentBstNode)
        {
            if (currentBstNode != null) {
                inOrder(currentBstNode.lefBstNode);
                System.out.print(currentBstNode.data + " ");
                inOrder(currentBstNode.righBstNode);
            }
        }
        
        public void wrapperInOrder()
        {
            inOrder(root);
        }
    }

    public static void main(String args[])
    {
        BstTree tree = new BstTree();
        tree.wrapperInsert(40);
        tree.wrapperInsert(20);
        tree.wrapperInsert(30);
        tree.wrapperInsert(10);
        tree.wrapperInOrder();
        System.out.println();
    }
}