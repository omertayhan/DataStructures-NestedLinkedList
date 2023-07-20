#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "BagliListe.hpp"
#include "FileHandler.hpp"
#include "nested_linked_list.hpp"
using namespace std;

#include "nested_linked_list.hpp"

int main()
{
    // ...

    ParentNode *parentList = nullptr;
    ParentNode *lastProcessedParent = nullptr; // Keep track of the last processed ParentNode

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
            }
            satirSayisi++;
        }

        printLists(parentList);

        inputFile.close();
    }
    else
    {
        cerr << "Dosya acilamadi!" << endl;
    }

    // ...

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

    return 0;
}
