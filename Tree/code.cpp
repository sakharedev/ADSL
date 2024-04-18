#include <iostream>

using namespace std;

struct Node {
    char data; // Change the data type to char
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(Node* newNode) {
        newNode->right = top;
        if (top != nullptr) {
            top->left = newNode;
        }
        top = newNode;
    }

    Node* pop() {
        if (isEmpty()) {
            cerr << "Error: Stack is empty." << endl;
            return nullptr;
        }

        Node* poppedNode = top;
        top = top->right;

        if (top != nullptr) {
            top->left = nullptr;
        }

        poppedNode->right = nullptr; 
        poppedNode->left = nullptr;

        return poppedNode;
    }

    Node* peek() {
        if (isEmpty()) {
            cerr << "Error: Stack is empty." << endl;
            return nullptr;
        }

        return top;
    }
};

class Tree
{
    private:
        

    public:
        Node *root;
        Tree()
        {
            root = nullptr;
        }
        
        void buildTree(string exp)
        {
            Stack stack;
            for(int i = 0; exp[i] != '\0'; i++)
            {
                if(isalpha(exp[i]) || isdigit(exp[i]))
                {
                    Node *newNode = new Node(exp[i]);
                    newNode -> left = nullptr;
                    newNode -> right = nullptr;
                    stack.push(newNode);
                }
                else
                {
                    Node *newNode = new Node(exp[i]);
                    newNode -> right = stack.pop();
                    newNode -> left = stack.pop();
                    stack.push(newNode);
                }
            }
            root = stack.peek();
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
        void postOrder(Node* current)
        {
            if(current!=nullptr)
            {
                postOrder(current->left);
                postOrder(current->right);
                cout<<current->data;
            }
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
};

int main() 
{
    Tree tree;
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;
    tree.buildTree(exp);
    tree.inOrder(tree.root);
    cout<<endl;
    tree.postOrder(tree.root);
    cout<<endl;
    tree.preOrder(tree.root);
    cout<<endl;
    return 0;
}