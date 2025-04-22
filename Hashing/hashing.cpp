#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value)
        {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class hashTable
{
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];
    
    public:
        int hash(string key)
        {
            int hash =0;
            for(int i=0;i<key.length();i++)
            {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue*23) % SIZE;
            }
            return hash;
        }

        void set(string key, int value)
        {
            int index = hash(key);
            Node *newNode = new Node(key,value);
            if(dataMap[index] == nullptr)
            {
                dataMap[index] = newNode;
            }
            else
            {
                Node* temp = dataMap[index];
                while(temp->next)
                {
                    temp=temp->next;
                }
                temp->next = newNode;
            }
        }

        int get(string key)
        {
            int index = hash(key);
            Node* temp = dataMap[index];

            while(temp)
            {
                if(temp->key == key) return temp-> value;

                temp = temp->next;
            }
            return 0;
        }

        vector<string> keys()
        {
            vector<string> allKeys;
            for(int i=0; i<SIZE; i++)
            {
                Node* temp =dataMap[i];
                while(temp)
                {
                    allKeys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return allKeys;
        }

        void printTable()
        {
            for(int i=0;i<SIZE; i++)
            {
                cout<<i<<":"<<endl;
                if(dataMap[i])
                {
                    Node* temp = dataMap[i];
                    while(temp)
                    {
                        cout<<" {"<<temp->key<<":"<<temp->value<<"}"<<endl;;
                        temp=temp->next;
                    }
                }
            }
        }

};

int main()
{
    hashTable* ht = new hashTable();

    ht->set("nails",100);
    ht->set("tile",50);
    ht->set("lumber",80);
    ht->set("bolts",200);
    ht->set("screws",140);

    ht->printTable();

    string find = "bolts";

    cout<<endl<<find<<":"<< ht->get(find)<<endl;

    vector<string> myKeys = ht->keys();
    for(auto i : myKeys)
    {
        cout<<i<<" ";
    }
    cout <<endl;

    return 0;
}