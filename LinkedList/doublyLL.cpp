#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node *next;
        Node *prev;
        Node(int value)
        {
            this->value=value;
            next=nullptr;
            prev=nullptr;
        }
};

class doublyLinkedList
{
    private:
        Node *head;
        Node * tail;
        int length;
    public:
        doublyLinkedList(int value)
        {
            Node *newNode = new Node(value);
            head=newNode;
            tail=newNode;
            length=1;
        }

        void append(int value)
        {
            Node *newNode = new Node(value);
            if(head)
            {
                tail->next= newNode;
                newNode->prev = tail;
                tail=newNode;
            }
            else
            {
                head=newNode;
                tail=newNode;
            }
            length++;
        }

        void prepend(int value)
        {
            Node *newNode = new Node(value);
            if(head)
            {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            else
            {
                head=newNode;
                tail=newNode;
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

            Node *temp=tail;
            if(length == 1)
            {
                head=nullptr;
                tail = nullptr;
            }
            else
            {
                tail = temp->prev;
                tail->next= nullptr;
            }
            delete temp;
            length--;

        }

        void deleteFirst()
        {
            if(head == nullptr)
            {
                cout<<"\nLL is empty.";
                return;
            }
            Node *temp=head;
            if(length == 1)
            {
                head=nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length --;
        }

        Node *get(int index)
        {
            if(index<0 || index>=length)
            {
                cout<<"\nIndex out of bounds";
                return nullptr;
            }

            Node *temp = head;
            for(int i=0; i<index; i++)
            {
                temp=temp->next;
            }
            return temp;

        }

        void set(int index, int value)
        {
            if(index<0 || index>=length)
            {
                cout<<"\nIndex out of bounds";
                return;
            }
            Node *temp = get(index);
            temp->value = value;
        }

        void insert(int index, int value)
        {
            if(index<0 || index>=length)
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

            Node *newNode = new Node(value);
            Node *after = get(index);
            Node *before = after->prev;

            newNode->next = after;
            newNode->prev = before;
            before->next = newNode;
            after -> prev = newNode;
            length++;
        }

        void deleteNode(int index)
        {
            if(index<0 || index>=length)
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
            Node *temp=get(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            
            delete temp;
            length --;
        }

        void printList()
        {
            Node *temp=head;
            cout<<"\nDLL: ";
            while(temp)
            {
                cout<<temp->value<<" ";
                temp=temp->next;
            }
        }

        void getLength()
        {
            cout<<"\nLength: "<<length;
        }

        ~doublyLinkedList()
        {
            Node *temp= head;
            while(head)
            {
                head=head->next;
                delete temp;
                temp = head;
            }
            cout<<"\nDLL destroyed.";
        }
};

int main()
{
    doublyLinkedList d(0);
    d.deleteLast();
    d.getLength();
    d.printList();

    d.prepend(4);
    d.getLength();
    d.printList();


    d.append(1);
    d.append(2);
    d.append(3);
    d.getLength();
    d.printList();

    d.deleteLast();
    d.getLength();
    d.printList();

    d.deleteFirst();
    d.getLength();
    d.printList();

    cout<<"\n Get method: "<<d.get(1)->value;

    d.append(3);
    d.append(4);
    d.getLength();
    d.printList();

    d.set(2,6);
    d.getLength();
    d.printList();

    cout<<"\n\nInsert:";

    d.insert(2,12);
    d.getLength();
    d.printList();

    cout<<"\n\nDeletNode:";

    d.deleteNode(3);
    d.getLength();
    d.printList();

}