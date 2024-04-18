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
        Node* top = nullptr;
    public:
        void push(Node* x)
        {
            if(top == nullptr)
            {
                top = x;
            }
            else
            {
                x->next = top;
                top = x;
            }
        } 
        Node* pop()
        {
            Node* p = top;
            top = top->next;
            return p;
        }
        Node* peek()
        {
            return top;
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
            Stack stack;
            int i = 0;
            while(exp[i] != '\0')
            {
                if(isalpha(exp[i]) || isdigit(exp[i]))
                {
                    Node* newNode = new Node(exp[i]);
                    newNode->right = newNode->left = nullptr;
                    stack.push(newNode);
                }
                else
                {
                    Node* newNode = new Node(exp[i]);
                    newNode->right = stack.pop();
                    newNode->left = stack.pop();
                    stack.push(newNode);
                }
                root = stack.peek();
                i++;
            }
        }

        void inOrder(Node* current)
        {
            if(current != nullptr)
            {
                inOrder(current->left);
                cout<<current->data;
                inOrder(current->right);
            }
        }

        void wrapperInOrder()
        {
            inOrder(root);
        }
};

int main()
{
    Tree tree;
    string exp = "ab+";
    tree.buildTree(exp);
    tree.wrapperInOrder();
    cout<<endl;
}