#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class binarySearchTree
{
    public:
        Node* root;
        
    public:
        binarySearchTree() // new way on implementation where we add the node using insert function
        {
            root = nullptr;    
        }
        /*
        //older way on creating a new node
         binarySearchTree(int value)
        {
            Node* newNode = new Node(value);
            root = newNode;
        }
        */
        
        void insert(int value)
        {
            Node* newNode = new Node(value);
            if(root == nullptr)
            {
                root = newNode;
                cout<<"Root Node: Node value->"<<newNode->value<<endl;
                return;
            }
            Node* temp = root;
            while (true)
            {
                if (newNode->value == temp->value)
                {
                    return;
                }

                if(newNode->value < temp->value)
                {
                    if(temp->left == nullptr)
                    {
                        temp->left = newNode;
                        cout<<"Node inserted at left: Node value->"<<newNode->value<<endl;
                        return;
                    }
                    temp = temp->left;
                }
                else
                {
                    if(temp->right == nullptr)
                    {
                        temp->right =newNode;
                        cout<<"Node inserted at right: Node value->"<<newNode->value<<endl;
                        return;
                    }
                    temp = temp ->right;
                }
            }
        }

        bool contains(int value)
        {
            //if(root== nullptr)// dont need as it is checked in the while loop
            //    return false;
            
            Node* temp  = root;
            while(temp)
            {
                if(value < temp->value)
                {
                    temp = temp->left;
                }
                else if (value > temp->value)
                {
                    temp = temp->right;
                }
                else
                {
                    return true;
                }
            }
            return false;  
        }


};

int main()
{
    binarySearchTree* bst = new binarySearchTree();  //or binarySearchTree bst;

    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(52);
    bst->insert(82);

    bst->insert(27);

    cout <<"new value: "<<bst->root->left->right->value<<endl;
    int find = 17;
    cout<<"Is "<<find<<" present:"<<bst->contains(find);

    return 0;
}
