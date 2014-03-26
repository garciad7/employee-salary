#include "List.h"

List::Node::Node(string s)
{
    data = s;
    previous = NULL;
    next = NULL;
}

List::List()
{
    first = NULL;
    last = NULL;
}

void List::push_back(string s)
{
    Node* newnode = new Node(s);
    if (last == NULL) // List is empty
    {
        first = newnode;
        last = newnode;
    }
    else
    {
        newnode->previous = last;
        last->next = newnode;
        last = newnode;
    }
}

void List::insert(Iterator iter, string s)
{
    if (iter.position == NULL)
    {
        push_back(s);
        return;
    }
    
    Node* after = iter.position;
    Node* before = after->previous;
    Node* newnode = new Node(s);
    newnode->previous = before;
    newnode->next = after;
    after->previous = newnode;
    if (before == NULL) // Insert at beginning
        first = newnode;
    else
        before->next = newnode;
}

List::Iterator List::erase(Iterator i)
{
    Iterator iter = i;
    assert(iter.position != NULL);
    Node* remove = iter.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    if (remove == first)
        first = after;
    else
        before->next = after;
    if (remove == last)
        last = before;
    else
        after->previous = before;
    iter.position = after;
    delete remove;
    return iter;
}

List::Iterator List::begin()
{
    Iterator iter;
    iter.position = first;
    iter.last = last;
    return iter;
}

List::Iterator List::end()
{
    Iterator iter;
    iter.position = NULL;
    iter.last = last;
    return iter;
}

List::Iterator::Iterator()
{
    position = NULL;
    last = NULL;
}

string List::Iterator::get() const
{
    assert(position != NULL);
    return position->data;
}

void List::Iterator::next()
{
    assert(position != NULL);
    position = position->next;
}

void List::Iterator::previous()
{
    if (position == NULL)
        position = last;
    else
        position = position->previous;
    assert(position != NULL);
}

bool List::Iterator::equals(Iterator b) const
{
    return position == b.position;
}
