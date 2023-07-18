#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"
class BagliListe
{
public:
    BagliListe();
    ~BagliListe();
    void ekle(int veri);

    void yazdir();
    void cikar();
    Dugum* get(int index);

private:
    Dugum *ilk;
};

#endif