/** 
* @file ParentNode.hpp
* @description ParentNode class for NestedList
* @course VERİ YAPILARI 1. Öğretim B
* @assignment 1.ÖDEV
* @date 22.7.23
* @author ÖMER TUFAN AYHAN tufan.ayhan@ogr.sakarya.edu.tr, Doğan Alperen Memur dogan.memur@ogr.sakarya.edu.tr 
*/
#ifndef ParentNode_hpp
#define ParentNode_hpp
#include "ChildNode.hpp"

class ParentNode
{
public:
    int value;
    ParentNode *next;
    ChildNode *child_list; // child düğümü işareti
    int satirSayisi;
};

#endif