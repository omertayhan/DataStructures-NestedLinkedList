#ifndef NestedLinkedList_HPP
#define NestedLinkedList_HPP

#include "ChildNode.hpp"
#include "ParentNode.hpp"

#include <iostream>
#include <string>

ChildNode *createChildNode(int value);
ParentNode *createParentNode(int value);
void addChildList(ParentNode *parent, int child_list_value);
void printLists(ParentNode *parent);

#endif // NestedLinkedList_HPP
