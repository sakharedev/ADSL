#include <iostream>
using namespace std;

struct node
{
    private:
        int data;
        node* left;
        node* right;
        node* next;
    friend class Stack;
    friend class BST;
};

class Stack
{
    private:
        node* top = NULL;
    public:
        void push(node* x)
        {
            if(top == NULL)
            {
                top = x;
            }
            else
            {
                x->next = top;
                top = x;
            }
        }

        node* pop()
        {
            node* temp = top;
            top = top->next;
            return temp;
        }

        node* peek()
        {
            return top;
        }

        bool isEmpty()
        {
            return top == NULL;
        }
};

class BST
{
    private:
        node* root;
    public:
        BST()
        {
            root = nullptr;
        }

        void insert1(int x)
        {
            insert(x, root);
        }
        void insert(int x, node* r)
        {
            if(root == nullptr)
            {
                //Empty tree
                node* newNode = new node();
                newNode->data = x;
                newNode->left = nullptr;
                newNode->right = nullptr;
                root = newNode;
            }
            else 
            {
                if(x < r->data)
                {
                    //Insert left
                    if(r->left == nullptr)
                    {
                        node* newNode = new node();
                        newNode->data = x;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        r->left = newNode;
                    }
                    else
                    {
                        insert(x, r->left);
                    }
                    
                }
                else
                {
                    //Insert right
                    if(r->right == nullptr)
                    {
                        node* newNode = new node();
                        newNode->data = x;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        r->right = newNode;
                    }
                    else
                    {
                        insert(x,r->right);
                    }
                    
                }
            } 

        }

        void inOrder(node* t)
        {
            Stack stack;
            while(1)
            {
                while(t != nullptr)
                {
                    stack.push(t);
                    t = t->left;
                }
                if(stack.isEmpty())
                {
                    break;
                }
                t = stack.pop();
                cout<<t->data<<" ";
                t = t->right;
                   
            }
        }

        void inOrder1()
        {
            inOrder(root);
        }

        void preOrder(node* t)
        {
            Stack stack;
            while(1)
            {
                while(t != nullptr)
                {
                    cout<<t->data<<" ";
                    stack.push(t);
                    t = t->left;
                }
                if(stack.isEmpty())
                {
                    break;
                }
                t = stack.pop();
                t = t->right;
                
            }
        }

        void preOrder1()
        {
            preOrder(root);
        }
        
};

int main()
{
    BST b1;
    int choice;
    while(choice != 4)
    {
        cout<<"1. Insert Value\n2. Inorder\n3. Preorder\n4. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                int ans;
                cout<<"Enter value: ";
                cin>>ans;
                b1.insert1(ans);
                break;
            case 2:
                cout<<"Inorder Traversal"<<endl;
                b1.inOrder1();
                cout<<endl;
                break;
            case 3:
                cout<<"Preorder Traversal"<<endl;
                b1.preOrder1();
                cout<<endl;
                break;
            case 4:
                break;
            default:
                cout<<"Wrong Value Entered"<<endl;
                break;
        }
    }
    return 0;
}