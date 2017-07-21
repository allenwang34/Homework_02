//
//  linkedlist.cpp
//  HW_02
//
//  Created by Yiyang Wang on 7/16/17.
//  Copyright © 2017 Yiyang Wang. All rights reserved.
//


#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

typedef string ItemType;

struct Node {
    ItemType value;
    Node *next;
};

class LinkedList {
    
private:
    Node *head;
    int linkedListSize;
    void printReverseRecur (Node *n) const;
   
public:
    
    // default constructor
    LinkedList();
    
    // copy constructor
    LinkedList(const LinkedList& rhs);
    // Destroys all the dynamically allocated memory
    // in the list.
    ~LinkedList();
    
    // assignment operator
    const LinkedList& operator=(const LinkedList& rhs);
    
    // Inserts val at the front of the list
    void insertToFront(const ItemType &val);
    
    // Prints the LinkedList
    void printList() const;
    
    
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
    int size() const;
};


void LinkedList:: printReverseRecur (Node *n) const {
    if (n == nullptr)
        return;
    printReverseRecur(n->next);
    cout << n->value << " ";
}



LinkedList::LinkedList()
    : head(nullptr) {
    linkedListSize = 0;
}


LinkedList::LinkedList(const LinkedList& rhs) {
    head = nullptr;
    Node *n = nullptr;
    for (Node *p = rhs.head; p != nullptr; p = p->next) {
        Node *newNode = new Node;
        newNode->next = nullptr;
        newNode->value = p->value;
        if (n == nullptr) {
            head = newNode;
        }
        if (n != nullptr) {
            n->next = newNode;
        }
        n = newNode;
    }
    
    linkedListSize = rhs.size();
}

LinkedList::~LinkedList() {
    Node *next = head;
    Node *prev = nullptr;
    while (next != nullptr) {
        prev = next;
        next = next->next;
        delete prev;
    }
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs) {
    LinkedList *newLinkedList = new LinkedList(rhs);
    
    head = newLinkedList->head;
    linkedListSize = newLinkedList->size();
    return *this;
}


void LinkedList::insertToFront(const ItemType &val) {
    Node *newNode = new Node;
    newNode -> value = val;
    newNode->next = head;
    head = newNode;
    linkedListSize++;
}

void LinkedList:: printList() const {
    for (Node *p = head; p!= nullptr; p = p->next) {
        cout << p->value << " ";
    }
    cout << endl;
}


bool LinkedList:: get(int i, ItemType& item) const {
    if (linkedListSize < i + 1)
        return false;
    Node *p = head;
    for (int j = 0; j != i; j++) {
        p = p->next;
    }
    item = p->value;
    return true;
}


void LinkedList:: reverseList() {
    Node *next = head;
    Node *prev = nullptr;
    
    while (head->next != nullptr){
        head = head->next;
        next->next = prev;
        prev = next;
        next = head;
    }
    next->next = prev;
}


void LinkedList::printReverse() const {
    printReverseRecur(head);
    cout << endl;
}


void LinkedList:: append(const LinkedList &other) {    //TODO don't know why it caused error
    Node *p = head;
    if (p==nullptr)
        return;
    for (; p -> next != nullptr; p = p->next) {
        ;
    }
    
    for (Node *n = other.head; n != nullptr; n = n->next) {
        Node *newNode = new Node;
        newNode -> value = n -> value;
        newNode -> next = nullptr;
        p->next = newNode;
        p = newNode;
        linkedListSize++;
    }
}


void LinkedList:: swap(LinkedList &other) {
    std::swap(head,other.head);
    std::swap(linkedListSize,other.linkedListSize);
}

int LinkedList:: size() const {
    return linkedListSize;
}










int main() {
	
    LinkedList e1;
    e1.insertToFront("A");
    e1.insertToFront("B");
    e1.insertToFront("C");
    e1.insertToFront("D");
    LinkedList e2;
    e2.insertToFront("X");
    e2.insertToFront("Y");
    e2.insertToFront("Z");
    e1.swap(e2);  // exchange contents of e1 and e2
    string s;
    assert(e1.size() == 3  &&  e1.get(0, s)  &&  s == "Z");
    assert(e2.size() == 4  &&  e2.get(2, s)  &&  s == "B");



}







/*int main() {
    LinkedList samplelist;
	LinkedList otherlist;
	string otherLetters[] = { "w","x","y","z" };
    string letters[] = {"a","b","c","d"};
    for (int i = 0; i < 4; i++) {
        samplelist.insertToFront(letters[i]);
    }
	for (int i = 0; i < 4; i++) {
		otherlist.insertToFront(otherLetters[i]);
	}
    cout << samplelist.size() << endl;
    samplelist.printList();
    cout << endl;
    
    //samplelist.reverseList();
	//samplelist.printReverse();
	//samplelist.append(otherlist);
    //samplelist.swap(otherlist);
    //samplelist.printList();
	//samplelist.swap(otherlist);
	//LinkedList copyList;
	//copyList = samplelist;
	//copyList.printList();
	//cout << endl;
	//otherlist.printList();
}*/


