#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "BagliListe.hpp"
#include "FileHandler.hpp"
#include "nested_linked_list.hpp"
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

// Function to get User input
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

double calculateParentChildAverage(ParentNode *parent)
{
    double sum = 0.0;
    int count = 0;
    ChildNode *child = parent->child_list;

    while (child != nullptr)
    {
        sum += child->value;
        count++;
        child = child->next;
    }

    return (count > 0) ? (sum / count) : 0.0;
}

// Function to calculate the average of child nodes for all parents and sum them
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

        getUserInputAndSwap(parentList, parentListOnes);
        double sumOfAveragesUp = calculateParentListAveragesAndSum(parentList);
        double sumOfAveragesDown = calculateParentListAveragesAndSum(parentListOnes);
        printf("Ust: %.2f\n", sumOfAveragesUp);
        printf("Ust: %.2f\n", sumOfAveragesDown);

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
