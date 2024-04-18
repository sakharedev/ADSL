#include <iostream>
using namespace std;

class bstNode
{
    int data;
    bstNode* left;
    bstNode* right;
    friend class bstTree;
};

class bstTree
{
    bstNode* root;
    public: 
        bstTree()
        {
            root = nullptr;
        }

        void Insert(int data, bstNode *r)
        {
            if(root == nullptr)
            {
                bstNode *t = new bstNode();
                t->data = data;
                t->left = t->right = nullptr;
                root = t;
            }
            else if (r->data > data)
            {
                if (r->left==nullptr)
                {
                    bstNode *t = new bstNode();
                    t->data = data;
                    r->left = t;
                    t->left = t->right = nullptr;
                }
                else
                {
                    Insert(data, r->left);
                }                    
            }
            else
            {
                if (r->right == nullptr)
                {
                    bstNode *t = new bstNode();
                    t->data = data;
                    r->right = t;
                    t->left = t->right = nullptr;
                }
                else
                {
                    Insert(data, r->right);
                }
                
            }
        }

        void wrapperInsert(int data)
        {
            Insert(data, root);
        }

        void inOrder(bstNode* current)
        {
            if(current!=nullptr)
            {
                inOrder(current->left);
                cout<<current->data<<" ";
                inOrder(current->right);
            }
        }
        void wrapperInorder()
        {
            inOrder(root);
        }
};

int main()
{
    bstTree b1;
    int choice, number;
    choice:
    cout<<"\nBinary Search Tree\n1. Insert 2. Display 3. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
        case 1:
            cout<<"Enter a Number to Insert: ";
            cin>>number;
            b1.wrapperInsert(number);
            cout<<number<<" inserted in the BST"<<endl;
            goto choice;
        case 2:
            cout<<"\nInorder BST: ";
            b1.wrapperInorder();
            cout<<endl;
            goto choice;
        case 3:
            cout<<"Exiting..."<<endl;
            return 0;
        default:
            cout<<"Enter Proper Input"<<endl;
            goto choice;
    }
    return 0;
}