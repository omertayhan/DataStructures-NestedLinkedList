#ifndef ParentNode_hpp
#define ParentNode_hpp
#include "ChildNode.hpp"

class ParentNode
{
public:
    int value;
    ParentNode *next;
    ChildNode *child_list; // Inner linked list için child düğümü işareti
    int satirSayisi;
};

#endif