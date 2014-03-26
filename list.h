#ifndef LIST_H
#define LIST_H

// The nested class Iterator must be public, so users can create an
// instance of the class. However, the nested class Node can be
// private, since users should never have direct access to the data
// fields.
// Because Node is private, its data fields can themselves be public.

#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class List
{
private:
    class Node; // Forward declaration
public:
    class Iterator;
    
    /**
     Constructs an empty list;
     */
    List();
    
    /**
     Appends an element to the list.
     @param s the value to append
     */
    void push_back(string s);
    
    /**
     Inserts an element into the list.
     @param iter the position before which to insert
     @param s the value to append
     */
    void insert(Iterator iter, string s);
    
    /**
     Removes an element from the list.
     @param i the position to remove
     @return an iterator pointing to the element after the
     erased element
     */
    Iterator erase(Iterator i);
    
    /**
     Gets the beginning position of the list.
     @return an iterator pointing to the beginning of the list
     */
    Iterator begin();
    
    /**
     Gets the past-the-end position of the list.
     @return an iterator pointing past the end of the list
     */
    Iterator end();
private:
    Node* first;
    Node* last;
};

class List::Node
{
public:
    /*
     Constructs a node with a given data value.
     @param s the data to store in this node
     */
    Node(string s);
    // The following can be public, since the class itself is private
    string data;
    Node* previous;
    Node* next;
};

class List::Iterator
{
public:
    /**
     Constructs an iterator that does not point into any list.
     */
    Iterator();
    
    /**
     Looks up the value at a position.
     @return the value of the node to which the iterator points
     */
    string get() const;
    
    /**
     Advances the iterator to the next node.
     */
    void next();
    
    /**
     Moves the iterator to the previous node.
     */
    void previous();
    
    /**
     Compares two iterators.
     @param b the iterator to compare with this iterator
     @return true if this iterator and b are equal
     */
    bool equals(Iterator b) const;
private:
    Node* position;
    Node* last;
    friend class List;
};



#endif
