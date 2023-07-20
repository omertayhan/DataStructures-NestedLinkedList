#ifndef NESTED_LINKED_LIST_HPP
#define NESTED_LINKED_LIST_HPP

#include <iostream>
#include <string>

struct ChildNode {
    int value;
    ChildNode* next;
};

struct ParentNode {
    int value;
    ParentNode* next;
    ChildNode* child_list; // Inner linked list için child düğümü işareti
};

ChildNode* createChildNode(int value);
ParentNode* createParentNode(int value);
void addChildList(ParentNode* parent, int child_list_value);
void printLists(ParentNode* parent);

#endif // NESTED_LINKED_LIST_HPP
