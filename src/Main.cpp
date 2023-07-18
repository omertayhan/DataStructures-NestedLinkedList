#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "BagliListe.hpp"
#include "FileHandler.hpp"
using namespace std;

// int main()
// {
//     BagliListe *liste = new BagliListe();

//     liste->ekle(11);
//     liste->ekle(22);
//     liste->ekle(33);
//     liste->ekle(44);
//     liste->ekle(55);

//     liste->yazdir();

//     liste->cikar();
//     liste->yazdir();
// }

int main()
{
    FileHandler fileHandler("Sayilar.txt");
    fileHandler.processFileAndDisplayArrays();
}
