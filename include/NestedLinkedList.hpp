/** 
* @file NestedLinkedList.hpp
* @description Transactions of NestedLinkedList
* @course VERİ YAPILARI 1. Öğretim B
* @assignment 1.ÖDEV
* @date 22.7.23
* @author ÖMER TUFAN AYHAN tufan.ayhan@ogr.sakarya.edu.tr
*/
#ifndef NestedLinkedList_HPP
#define NestedLinkedList_HPP

#include "ChildNode.hpp"
#include "ParentNode.hpp"

#include <iostream>

ChildNode *createChildNode(int value);
ParentNode *createParentNode(int value);
void addChildList(ParentNode *parent, int child_list_value);
void printLists(ParentNode *parent);

#endif // NestedLinkedList_HPP
