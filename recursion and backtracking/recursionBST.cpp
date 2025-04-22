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
        binarySearchTree() // new way on implementation where we add the node using rInsert function
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
       
        
        void rInsert(Node* &node, int value)
        {            
            if(node == nullptr) 
            {
                node = new Node(value);
                return;
            }
            if(node->value > value)
            {
                rInsert(node->left, value);
            }
            else if( node->value < value)
            {
                rInsert(node->right, value);
            }
            return;
        }

        void rInsert(int value)
        {
            if (root == nullptr)
            {
                root = new Node(value);
                return;
            }
            else
            {
                rInsert(root, value);
            }
        }   

        void rDelete(Node* & node, int value)
        {
            if(value < node->value)
            {
                rDelete(node->left, value);
            }
            else if(value > node->value)
            {
                rDelete(node->right, value);
            }
            else
            {
                if(node->left == nullptr && node->right == nullptr) // leaf node condition
                {
                    delete node;
                    node = nullptr;
                }
                else if(node->left == nullptr) //right single child
                {
                    Node* temp = node->right;
                    delete node;
                    node = temp;
                }
                else if(node->right == nullptr) //left single child
                {
                    Node* temp = node->left;
                    delete node;
                    node = temp;
                }
                else
                {
                    //find min value
                    Node* minNode = node->right;
                    while (minNode->left != nullptr)
                    {
                        minNode = minNode->left;
                    }
                    node->value = minNode->value;
                    rDelete(node->right, minNode->value);
              
                }
            }

        }

        void rDelete(int value)
        {
            if ( root == nullptr)
            {
                cout << " String empty.";
                return; 
            }
            rDelete(root, value);
        }

        bool rContains(Node* temp, int value)
        {
            if(temp == nullptr) return false;

            //if(temp->value == value) return true;

            if(temp->value > value)
                return rContains(temp->left, value);
            else if(temp->value < value)
                return rContains(temp->right, value);
            else return true;   
        }

        bool rContains(int value)
        {
            return rContains(root, value);
        }

};

int main()
{
    binarySearchTree* bst = new binarySearchTree();  //or binarySearchTree bst;

    bst->rInsert(47);
    bst->rInsert(21);
    bst->rInsert(76);
    bst->rInsert(18);
    bst->rInsert(52);
    bst->rInsert(82);
    bst->rInsert(9);
    bst->rInsert(27);
    bst->rInsert(30);
    bst->rInsert(25);
    bst->rInsert(23);
    bst->rInsert(26);

    cout <<"new value: "<<bst->root->left->right->value<<endl;

    //cout <<"new value: "<<bst->root->left->right->value<<endl;
    int find = 76;
    cout<<"Is "<<find<<" present:"<<boolalpha<<bst->rContains(find);

   //bst->rDelete(52); //leaf node condition
    //bst->rDelete(18); // single left child
   // bst->rDelete(27); // single right child

   bst->rDelete(21); //middle element



    return 0;
}
