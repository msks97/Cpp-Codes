#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Add a node to the end
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Find the k-th node from the end (Two-pointer technique)
    Node* findKthFromEnd(int k) {
        if (!head || k <= 0) return nullptr;

        Node* first = head;
        Node* second = head;

        // Move the first pointer k steps ahead
        for (int i = 0; i < k; ++i) {
            if (!first) return nullptr;  // k is larger than the list size
            first = first->next;
        }

        // Move both pointers until the first reaches the end
        while (first) {
            first = first->next;
            second = second->next;
        }

        return second;  // Second is now at the k-th node from the end
    }

    // Print the linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;
    
    // Adding nodes to the list
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    std::cout << "Linked List: ";
    list.printList();

    int k = 2;  // Find the 2nd node from the end
    Node* result = list.findKthFromEnd(k);

    if (result) {
        std::cout << "The " << k << "-th node from the end is: " << result->data << std::endl;
    } else {
        std::cout << "Invalid value of k or list is too short." << std::endl;
    }

    return 0;
}
