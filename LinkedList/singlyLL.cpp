#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node *next;
        Node(int value)
        {
            this->value=value;
            next=nullptr;
        }
};

class linkedList
{
    private:
        Node *head;
        Node *tail;
        int length;
    
    public:
        linkedList(int value)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void append(int value)
        {
            Node *newNode = new Node(value);
            if(head)
            {
                tail->next=newNode;
                tail = newNode;
            }
            else
            {
                head = newNode;
                tail = newNode;
            }
            length++;
        }
        
        void prepend(int value)
        {
            Node *newNode = new Node(value);
            if(head)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                head = newNode;
                tail = newNode;
            }
            length++;

        }

        void deleteLast()
        {
            if(head == nullptr)
            {
                cout<<"\nLL is empty.";
                return;
            }
            
            Node *temp=head;
            if(length ==1) // or head ==tail
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node *pre=head;
                while(temp->next)
                {
                    pre=temp;
                    temp=temp->next;
                }
                tail=pre;
                tail->next=nullptr;
            }
            length--;  
            delete temp;     
        }

        void deleteFirst()
        {
            if(head == nullptr)
            {
                cout<<"\nLL is empty.";
                return;
            }

            Node *temp=head;
            if(length ==1) // or head ==tail
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head=head->next;
            }
            length--;  
            delete temp;

        }

        Node *get(int index) //when input is index
        {
            if(index<0 || index >=length)
                return nullptr;
            Node *temp = head;
            for(int i=0; i<index;i++)
            {
                temp=temp->next;
            }
            return temp;
        }

        void set(int index, int value)
        {
            Node *temp = get(index);
            if(temp) //not a nullptr
            {
                temp->value = value;
                cout<<"\nValue modified";
            }
            else
            {
                cout<<"\nIndex out of bounds";
            }    
        }

        void insert(int index, int value)
        {
            if(index<0 || index >=length)
            {
                cout<<"\nIndex out of bounds";
                return;
            }    

            if(index==0)
            {
                prepend(value);
                cout<<"\nInsterted as prepend";
                return;
            }

            if(index==length)
            {
                append(value);
                cout<<"\nInsterted as append";
                return;
            }

            Node *newNode= new Node(value);
            Node *temp = get(index-1);
            newNode->next =temp->next;
            temp->next=newNode;
            length++;
        }

        void deleteNode(int index)
        {
            if(index<0 || index >=length)
            {
                cout<<"\nIndex out of bounds";
                return;
            }    

            if(index==0)
            {
                cout<<"\nIDeleted as deleteFirst";
                return deleteFirst();
            }

            if(index==length-1)
            {
                cout<<"\nDeleted as deleteLast";
                return deleteLast();
            }

            Node *prev = get(index-1);
            Node *temp= prev->next;
            prev->next=temp->next;
            delete temp;
            length--;
        }

        void reverse()
        {
            Node *temp=head;
            head=tail;
            tail=temp;

            Node *after=temp->next;
            Node* before = nullptr;

            for(int i=0; i< length; i++)
            {
                after=temp->next;
                temp->next=before;
                before=temp;
                temp=after;
            }
        }

        void printList()
        {
            Node *temp= head;
            cout<<"\nLL list:";
            while(temp)
            {
                cout << temp->value <<" ";
                temp = temp->next;
            } 
        }
        
        int getLength()
        {
            cout<<"\nLength: ";
            return length;
        }

        ~linkedList()
        {
            Node *temp= head;
            while(head)
            {
                head=head->next;
                delete temp;
                temp = head;
            }
            cout<<"\nLL destroyed.";
        }
};

int main()
{
    linkedList l(0); //1
    l.append(5); //2
    l.append(6);//3
    l.prepend(7); //0
    l.printList();
    cout<<l.getLength();

    cout<<"\nGet: "<<l.get(2)->value;
    l.set(2,20);
    l.printList();

    l.insert(2,10);
    l.printList();

    l.reverse();
    cout<<"\nReverse ";
    l.printList();

    l.deleteNode(2);
    l.printList();

    l.deleteNode(3);
    l.printList();

    l.deleteNode(0);
    l.printList();

    l.deleteNode(1);
    l.printList();



}