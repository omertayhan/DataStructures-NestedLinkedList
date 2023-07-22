/** 
* @file NestedLinkedList.cpp
* @description Transactions of NestedLinkedList
* @course VERİ YAPILARI 1. Öğretim B
* @assignment 1.ÖDEV
* @date 22.7.23
* @author ÖMER TUFAN AYHAN tufan.ayhan@ogr.sakarya.edu.tr, Doğan Alperen Memur dogan.memur@ogr.sakarya.edu.tr 
*/
#include "NestedLinkedList.hpp"

ChildNode *createChildNode(int value)
{
    ChildNode *newNode = new ChildNode;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

ParentNode *createParentNode(int value)
{
    ParentNode *newNode = new ParentNode;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->child_list = nullptr;
    return newNode;
}

void addChildList(ParentNode *parent, int child_list_value)
{
    ChildNode *newChildNode = createChildNode(child_list_value);

    if (parent->child_list == nullptr)
    {
        parent->child_list = newChildNode;
    }
    else
    {
        ChildNode *currentChild = parent->child_list;
        while (currentChild->next != nullptr)
        {
            currentChild = currentChild->next;
        }
        currentChild->next = newChildNode;
    }
}

void printLists(ParentNode *parent)
{
    ParentNode *currentParent = parent;
    while (currentParent != nullptr)
    {
        std::cout << "Parent List Value: " << currentParent->value << std::endl;

        ChildNode *currentChild = currentParent->child_list;
        while (currentChild != nullptr)
        {
            std::cout << "  Child List Value: " << currentChild->value << std::endl;
            currentChild = currentChild->next;
        }

        currentParent = currentParent->next;
    }
}
