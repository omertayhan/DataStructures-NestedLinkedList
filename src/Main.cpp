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
    ParentNode *parentList = nullptr;
    BagliListe *list = new BagliListe();

    ifstream inputFile("Sayilar.txt");

    if (inputFile.is_open())
    {
        int satirSayisi, prevSatirSayisi = 0;
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
                    if (parentList == nullptr || satirSayisi > prevSatirSayisi)
                    {
                        parentList = createParentNode(sayi);
                        addChildList(parentList, onlarBasamagi);
                    }
                    else
                    {
                        addChildList(parentList, onlarBasamagi);
                    }

                    printLists(parentList);
                }
            }
            satirSayisi++;
            
        }

        inputFile.close();
    }
    else
    {
        cerr << "Dosya acilamadi!" << endl;
    }

    // Bellekten serbest bırakma (Memory deallocation)
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
