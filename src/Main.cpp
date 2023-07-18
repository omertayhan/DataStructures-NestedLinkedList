#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "BagliListe.hpp"
#include "FileHandler.hpp"
using namespace std;

void swapNodesBetweenLinkedLists(BagliListe &a, BagliListe &b, int indexA, int indexB)
{
    Dugum *nodeA = a.get(indexA);
    Dugum *nodeB = b.get(indexB);

    if (!nodeA || !nodeB)
    {
        std::cout << "Geçersiz indis!" << std::endl;
        return;
    }

    int tempData = nodeA->veri;
    nodeA->veri = nodeB->veri;
    nodeB->veri = tempData;
}

void SwapLinkedLists()
{
    ifstream inputFile("Sayilar.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Dosya acilamadi!" << endl;
    }

    BagliListe onlarBasamagi;
    BagliListe birlerBasamagi;

    string line;
    getline(inputFile, line);
    istringstream iss(line);
    int num;

    while (iss >> num)
    {
        onlarBasamagi.ekle(num / 10);  // Onlar basamağı için
        birlerBasamagi.ekle(num % 10); // Birler basamağı için
    }

    cout << "Onlar basamagi linked list:" << endl;
    onlarBasamagi.yazdir();

    cout << "Birler basamagi linked list:" << endl;
    birlerBasamagi.yazdir();

    int konumA, konumB;
    cout << "Onlar basamagi icin KonumA degerini giriniz: ";
    cin >> konumA;
    cout << "Birler basamagi icin KonumB degerini giriniz: ";
    cin >> konumB;

    swapNodesBetweenLinkedLists(onlarBasamagi, birlerBasamagi, konumA, konumB);

    cout << "Onlar basamagi linked list:" << endl;
    onlarBasamagi.yazdir();

    cout << "Birler basamagi linked list:" << endl;
    birlerBasamagi.yazdir();

    inputFile.close();
}

int main()
{
    SwapLinkedLists();
}
