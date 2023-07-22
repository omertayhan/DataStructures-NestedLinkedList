#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "BagliListe.hpp"
#include "FileHandler.hpp"
#include "nested_linked_list.hpp"
using namespace std;

void DeallocationMemory(ParentNode *&parentList)
{
    // Memory deallocation
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

void processNode(ParentNode *&parentList, ParentNode *&lastProcessedParent, int sayi, int satirSayisi, int onlarBasamagi)
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
    for (int i = 1; i < KonumB && parentB != nullptr; ++i)
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

void getUserInputAndSwap(ParentNode *&parentList1, ParentNode *&parentList2)
{
    int KonumA, KonumB;

    std::cout << "Enter the value of KonumA: ";
    std::cin >> KonumA;

    std::cout << "Enter the value of KonumB: ";
    std::cin >> KonumB;

    // Call the swapParentNodesBetweenLists function with user input
    swapParentNodesBetweenLists(parentList1, parentList2, KonumA, KonumB);
}

int main()
{
    ParentNode *parentList = nullptr;
    ParentNode *lastProcessedParent = nullptr; // Keep track of the last processed ParentNode

    ParentNode *parentListOnes = nullptr;
    ParentNode *lastProcessedParentOnes = nullptr; // Keep track of the last processed ParentNode

    ifstream inputFile("Sayilar.txt");

    if (inputFile.is_open())
    {
        int satirSayisi = 0; // Initialize satirSayisi to 0
        string line;

        while (getline(inputFile, line))
        {
            int sayi, onlarBasamagi, birlerBasamagi;
            istringstream iss(line);
            while (iss >> sayi)
            {
                if (sayi >= 10 && sayi < 100)
                {
                    onlarBasamagi = (sayi / 10) % 10;
                    birlerBasamagi = sayi % 10;

                    // Call the method with appropriate arguments
                    processNode(parentList, lastProcessedParent, sayi, satirSayisi, onlarBasamagi);
                    processNode(parentListOnes, lastProcessedParentOnes, sayi, satirSayisi, birlerBasamagi);
                }
            }
            satirSayisi++;
        }

        printLists(parentList);
        cout << endl;
        printLists(parentListOnes);
        getUserInputAndSwap(parentList, parentListOnes);

        printLists(parentList);
        cout << endl;
        printLists(parentListOnes);

        inputFile.close();
    }
    else
    {
        cerr << "Dosya acilamadi!" << endl;
    }

    DeallocationMemory(parentList);
    DeallocationMemory(parentListOnes);

    return 0;
}
