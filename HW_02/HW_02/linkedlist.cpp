//
//  linkedlist.cpp
//  HW_02
//
//  Created by Yiyang Wang on 7/16/17.
//  Copyright © 2017 Yiyang Wang. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

typedef string ItemType;

struct Node {
    ItemType value;
    Node *next;
    
    Node (ItemType d) {
        next = nullptr;
        value = d;
    }
};

class LinkedList {
    
private:
    Node *head;
    int linkedListSize;
    
public:
    
    // default constructor
    LinkedList() : head(nullptr) {
        linkedListSize = 0;
    }
    
    // copy constructor
    LinkedList(const LinkedList& rhs);
    
    // Destroys all the dynamically allocated memory
    // in the list.
    ~LinkedList() {
        Node *next = head;
        Node *prev = nullptr;
        for ( ; next!=nullptr; next = next->next)
            prev = next;
            delete prev;
    }
    
    // assignment operator
    const LinkedList& operator=(const LinkedList& rhs);
    
    // Inserts val at the front of the list
    void insertToFront(const ItemType &val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        linkedListSize++;
    }
    
    // Prints the LinkedList
    void printList() const {
        for (Node *p = head; p!= nullptr; p = p->next) {
            cout << p->value << endl;
        }
    }
    
    // Sets item to the value at position i in this
    // LinkedList and return true, returns false if
    // there is no element i
    bool get(int i, ItemType& item) const;
    
    // Reverses the LinkedList
    void reverseList();
    
    // Prints the LinkedList in reverse order
    void printReverse() const;
    
    // Appends the values of other onto the end of this
    // LinkedList.
    void append(const LinkedList &other);
    
    // Exchange the contents of this LinkedList with the other one.
    void swap(LinkedList &other);
    
    // Returns the number of items in the Linked List.
    int size() const {
        return linkedListSize;
    }
};






int main() {
    LinkedList samplelist;
    for (int i = 0; i < 3; i++) {
        string a = "hello";
        samplelist.insertToFront(a);
    }
    cout << samplelist.size() << endl;
    samplelist.printList();
}


