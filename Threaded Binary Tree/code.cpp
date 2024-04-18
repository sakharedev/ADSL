// Threaded Binary Tree

#include <iostream>
using namespace std;

struct TBTNode
{
    int data;
    TBTNode *left;
    TBTNode *right;
    bool leftThread;
    bool rightThread;
};

class TBT
{
    TBTNode *root;
    TBTNode *dummyNode;
    public:
        TBT()
        {
            root = nullptr;
        }

        TBTNode* createTBTNode()
        {
            TBTNode* newTBTNode = new TBTNode();
            newTBTNode->left = newTBTNode->right = nullptr;
            newTBTNode->leftThread = newTBTNode->rightThread = true;
            cout<<"\nEnter Data: ";
            cin>>newTBTNode->data;
            return newTBTNode;
        }
        
        void create() //Create Tree
        {
            TBTNode* newNode;
            newNode = createTBTNode();
            if(root==nullptr)
            {
                root = newNode;
                dummyNode = new TBTNode();
                dummyNode->data = -999;
                dummyNode->left = root;
                dummyNode->right = dummyNode;
                dummyNode->leftThread = dummyNode->rightThread = true;
                root->left = root->right = dummyNode;
            }
            else
                insert(root,newNode);
        }

        void insert(TBTNode* root, TBTNode* newNode)
        {
            if (newNode->data < root->data) // Left Subtree
            {
                if (root->leftThread == true)
                {
                    newNode->left = root->left;
                    newNode->right = root;
                    root->left = newNode;
                    root->leftThread = false;
                }
                else
                    insert(root->left, newNode);
            }

            else if(newNode->data >= root->data) // Right Subtree
            {
                if(root->rightThread == true)
                {
                    newNode->right = root->right;
                    newNode->left = root;
                    root->rightThread = false;
                    root->right = newNode;
                }
                else
                    insert(root->right, newNode);
            }
        }

        void inOrder(TBTNode* temp, TBTNode* dummyNode) //Inorder display  (root, headerNode)
        {
            while (temp != dummyNode)
            {
                while (temp->leftThread == false) // Left Subtree
                {
                    temp = temp->left;
                }
                cout<<" "<<temp->data; // Print Data
                while (temp->rightThread == true) // Right Subtree
                {
                    temp = temp->right;
                    if(temp == dummyNode)
                        return;
                    cout<<" "<<temp->data;
                }
                temp = temp->right;
            }
            
        }

        void display()
        {
            inOrder(root, dummyNode);
        }
};

int main()
{
    TBT tree;
    choice:
    int choice;
    cout<<"\n\nThreaded Binary Search Tree\n1. Insert 2. Display 3. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
            tree.create();
            goto choice;
        case 2:
            cout<<"\nInorder BST: ";
            tree.display();
            cout<<endl;
            goto choice;
        case 3:
            cout<<"Exiting..."<<endl;
            return 0;
        default:
            cout<<"Enter Proper Input"<<endl;
            goto choice;
    }
}

