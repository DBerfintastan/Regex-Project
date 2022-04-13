#ifndef AVLAGAC_HPP
#define AVLAGAC_HPP
#include "Dugum.hpp"
#include <iostream>
using namespace std;
class Avl
{
public:
    Dugum *kok=NULL;
    int max(int a, int b);
    int yukseklikHesapla(Dugum *dugum);
    Dugum *yeniDugum(int veri,string isim,int yas);
    Dugum *sagaDon(Dugum *dugum);
    Dugum *solaDon(Dugum *dugum);
    int dengele(Dugum *dugum);
    Dugum *ekle(Dugum *dugum, int veri,string isim, int yas);
    void sirala(Dugum* kok, int level);
    void yazdir(Dugum* kok);
    void stackDoldur(Dugum *kok, int level);
};

#endif
