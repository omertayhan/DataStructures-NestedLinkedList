/**
 * @file NestedLinkedList.hpp
 * @description It contains about required actions methods in homework
 * @course VERİ YAPILARI 1. Öğretim B
 * @assignment 1.ÖDEV
 * @date 22.7.23
 * @author ÖMER TUFAN AYHAN tufan.ayhan@ogr.sakarya.edu.tr, Doğan Alperen Memur dogan.memur@ogr.sakarya.edu.tr
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "FileHandler.hpp"
#include "NestedLinkedList.hpp"
using namespace std;

// Memory deallocation
void DeallocationMemory(ParentNode *&parentList)
{
    while (parentList != nullptr)
    {
        ParentNode *tempParent = parentList;
        parentList = parentList->next;

        ChildNode *currentChild = tempParent->child_list;
        while (currentChild != nullptr)
        {
            ChildNode *tempChild = currentChild;
            currentChild = currentChild->next;
            delete tempChild;
        }
        delete tempParent;
    }
}

// Function to add parent list childlists
void addChildNodeToParentNode(ParentNode *&parentList, ParentNode *&lastProcessedParent, int sayi, int satirSayisi, int onlarBasamagi)
{
    // Check if a new ParentNode needs to be created
    if (parentList == nullptr || lastProcessedParent == nullptr || satirSayisi > lastProcessedParent->satirSayisi)
    {
        ParentNode *newParent = createParentNode(sayi);
        newParent->satirSayisi = satirSayisi; // Set satirSayisi for the new ParentNode
        addChildList(newParent, onlarBasamagi);

        // Update the pointers for the last processed ParentNode
        if (lastProcessedParent != nullptr)
            lastProcessedParent->next = newParent;

        lastProcessedParent = newParent;

        // If parentList is empty, set it to the newly created ParentNode
        if (parentList == nullptr)
            parentList = lastProcessedParent;
    }
    else
    {
        addChildList(lastProcessedParent, onlarBasamagi);
    }
}

// Function to swap indexes according to output
void swapParentNodesBetweenLists(ParentNode *&parentList1, ParentNode *&parentList2, int KonumA, int KonumB)
{
    // Find the parent node at position KonumA in ParentLinkedList 1
    ParentNode *parentA = parentList1;
    for (int i = 1; i < KonumA && parentA != nullptr; ++i)
    {
        parentA = parentA->next;
    }

    // Find the parent node at position KonumB in ParentLinkedList 2
    ParentNode *parentB = parentList2;
    for (int i = 1; i <= KonumB && parentB != nullptr; ++i)
    {
        parentB = parentB->next;
    }

    // If either parentA or parentB is not found, return since the swap cannot be performed
    if (parentA == nullptr || parentB == nullptr)
    {
        return;
    }

    // Swap the parent nodes between the two lists
    ParentNode *tempNextA = parentA->next;
    ParentNode *tempNextB = parentB->next;

    // Update parent pointers
    if (parentA == parentList1)
    {
        parentList1 = parentB;
    }
    else
    {
        ParentNode *prevParentA = parentList1;
        while (prevParentA->next != parentA)
        {
            prevParentA = prevParentA->next;
        }
        prevParentA->next = parentB;
    }

    if (parentB == parentList2)
    {
        parentList2 = parentA;
    }
    else
    {
        ParentNode *prevParentB = parentList2;
        while (prevParentB->next != parentB)
        {
            prevParentB = prevParentB->next;
        }
        prevParentB->next = parentA;
    }

    parentA->next = tempNextB;
    parentB->next = tempNextA;
}

// Function to get the total number of lines in a file
int getTotalLinesFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Dosya acilamadi: " << filename << endl;
        return -1;
    }

    int totalLines = 0;
    string line;
    while (getline(file, line))
    {
        totalLines++;
    }

    file.close();
    return totalLines;
}

// Function to check if the given position is valid in the file
bool isValidPosition(int position)
{

    const string filename = "Sayilar.txt";
    // Assuming you have a function to get the total number of lines in the file
    int totalLines = getTotalLinesFromFile(filename); // Replace this with the actual function to get the total lines

    return (position >= 0 && position <= totalLines);
}

// Function to get User input
void getUserInputAndSwap(ParentNode *&parentList1, ParentNode *&parentList2)
{
    int KonumA, KonumB;

    while (true)
    {
        cout << "KonumA: ";
        cin >> KonumA;

        if (isValidPosition(KonumA))
            break;
        else
            cout << "Hatali giris! KonumA dosyada gecerli bir satir degil." << endl;
    }

    while (true)
    {
        cout << "KonumB: ";
        cin >> KonumB;

        if (isValidPosition(KonumB))
            break;
        else
            cout << "Hatali giris! KonumA dosyada gecerli bir satir degil." << endl;
    }

    // Call the swapParentNodesBetweenLists function with user input
    swapParentNodesBetweenLists(parentList1, parentList2, KonumA, KonumB);
}
// Function to calculate the average of child nodes for all parents and sum them up
double calculateParentListAveragesAndSum(ParentNode *parentList)
{
    double totalSum = 0.0;
    int totalCount = 0;

    // Find the parent with the maximum number of child nodes
    int maxChildNodes = 0;
    ParentNode *currentParent = parentList;
    while (currentParent != nullptr)
    {
        ChildNode *child = currentParent->child_list;
        int childCount = 0;
        while (child != nullptr)
        {
            childCount++;
            child = child->next;
        }

        if (childCount > maxChildNodes)
            maxChildNodes = childCount;

        currentParent = currentParent->next;
    }

    // Calculate the average of corresponding child nodes for all parents and sum them up
    for (int i = 0; i < maxChildNodes; i++)
    {
        double sumOfCorrespondingChildNodes = 0.0;
        int childNodeCount = 0;

        currentParent = parentList;
        while (currentParent != nullptr)
        {
            ChildNode *child = currentParent->child_list;
            int count = i;
            while (count > 0 && child != nullptr)
            {
                child = child->next;
                count--;
            }

            if (child != nullptr)
            {
                sumOfCorrespondingChildNodes += child->value;
                childNodeCount++;
            }

            currentParent = currentParent->next;
        }

        // Only consider non-null child nodes for average calculation
        //  ODEVDEKİ ÇIKTIYA GÖRE DÜZENLENDİ
        if (childNodeCount > 0)
        {
            totalSum += (sumOfCorrespondingChildNodes / childNodeCount);
            totalCount++;
        }
    }

    return (totalCount > 0) ? totalSum : 0.0;
}

int main()
{
    ParentNode *parentList = nullptr;
    ParentNode *lastProcessedParent = nullptr;

    ParentNode *parentListOnes = nullptr;
    ParentNode *lastProcessedParentOnes = nullptr;

    const string filename = "Sayilar.txt";
    FileHandler fileHandler(filename);

    if (fileHandler.openFileForReading())
    {
        int satirSayisi = 0;
        string line;

        while (getline(fileHandler.getInfile(), line))
        {
            int sayi, onlarBasamagi, birlerBasamagi;
            istringstream iss(line);
            while (iss >> sayi)
            {
                if (sayi >= 10 && sayi < 100)
                {
                    onlarBasamagi = (sayi / 10) % 10;
                    birlerBasamagi = sayi % 10;

                    addChildNodeToParentNode(parentList, lastProcessedParent, sayi, satirSayisi, onlarBasamagi);
                    addChildNodeToParentNode(parentListOnes, lastProcessedParentOnes, sayi, satirSayisi, birlerBasamagi);
                }
            }
            satirSayisi++;
        }

        getUserInputAndSwap(parentList, parentListOnes);
        double sumOfAveragesUp = calculateParentListAveragesAndSum(parentList);
        double sumOfAveragesDown = calculateParentListAveragesAndSum(parentListOnes);
        cout << "Ust: " << sumOfAveragesUp << endl;
        cout << "Alt: " << sumOfAveragesDown << endl;

        fileHandler.closeFile();
    }
    else
    {
        cerr << "Dosya acilamadi!" << endl;
    }

    DeallocationMemory(parentList);
    DeallocationMemory(parentListOnes);

    return 0;
}
