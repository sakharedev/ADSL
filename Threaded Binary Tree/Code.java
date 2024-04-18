class Code
{

    class TBTNode
    {
        int data;
        TBTNode rightNode;
        TBTNode lefNode;
        boolean leftThread;
        boolean rightThread;
    }

    class TBT
    {
        TBTNode rootNode;
        TBTNode dummyNode;

        TBT()
        {
            rootNode = null;
        }

        TBTNode createTBTNode()
        {
            TBTNode newNode = new TBTNode();
            newNode.lefNode = newNode.rightNode = null;
            newNode.rightThread = newNode.leftThread = true;
            
            return newNode;
        }
    }
    public static void main(String args[])
    {

    }
}