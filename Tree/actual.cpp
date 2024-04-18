#include <iostream>
using namespace std;

class Node
{
    private:
        char data;
        Node* left;
        Node* right;
        Node* next;
    public:
        Node()
        {
            left = nullptr;
            right = nullptr;
        }
        Node(char value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
        friend class Stack;
        friend class Tree;
};

class Stack
{
    private:
	    Node* head = NULL;
    public:
        void push(Node* x)
        {
            if (head == NULL)
            {
                head = x;
            }
            else 
            {
                x->next = head;
                head = x;
            }
        }
        Node* pop()
        {
            Node* p = head;
            head = head->next;
            return p;
        }
        Node* peek()
        {
            return head;
        }
};

class Tree
{
    private:
        Node* root;
    public:
        Tree()
        {
            root = new Node();
        }

        void buildTree(string exp)
        {
            int i = 0;
            Stack stack;
            while (exp[i]!=0)
            {
                if(isalpha(exp[i]) || isdigit(exp[i]))
                {
                    Node *newNode = new Node(exp[i]);
                    newNode->left = nullptr;
                    newNode->right = nullptr;
                    stack.push(newNode);
                }
                else
                {
                    Node *newNode = new Node(exp[i]);
                    newNode -> right = stack.pop();
                    newNode -> left = stack.pop();
                    stack.push(newNode);
                }
                root = stack.peek();
                i++;
            }
        }

        void inOrder(Node* current)
        {
            if(current!=nullptr)
            {
                inOrder(current->left);
                cout<<current->data;
                inOrder(current->right);
            }
        }
        void wrapperInorder()
        {
            inOrder(root);
        }

        void preOrder(Node* current)
        {
            if(current!=nullptr)
            {
                cout<<current->data;
                preOrder(current->left);
                preOrder(current->right);
            }
        }
        void wrapperPreorder()
        {
            preOrder(root);
        }

        void postOrder(Node* current)
        {
            if(current!=nullptr)
            {
                postOrder(current->left);
                postOrder(current->right);
                cout<<current->data;
            }
        }
        void wrapperPostorder()
        {
            postOrder(root);
        }
};

int main() 
{
    Tree tree;
    string exp;
    choice:
        int choice;
        cout<<"\n\nEnter a Choice\n1. Post Order\n2. Pre Order\n3. In Order\n4. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> exp;
                tree.buildTree(exp);
                cout<<"\nPost Order: ";
                tree.wrapperPostorder();
                cout<<endl;
                goto choice;
            case 2:
                cout << "Enter postfix expression: ";
                cin >> exp;
                tree.buildTree(exp);
                cout<<"\nPre Order: ";
                tree.wrapperPreorder();
                cout<<endl;
                goto choice;
            case 3:
                cout << "Enter postfix expression: ";
                cin >> exp;
                tree.buildTree(exp);
                cout<<"\nIn Order: ";
                tree.wrapperInorder();
                cout<<endl;
                goto choice;
            case 4:
                cout<<"Exiting..."<<endl;
                return 0;
            default:
                cout<<"Wrong Input (1/2/3/4)"<<endl;
                goto choice;
        }
    return 0;
}