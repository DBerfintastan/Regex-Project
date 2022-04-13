#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include "Kisi.hpp"
#include "Stack.hpp"
using namespace std;
class Dugum
{
public:
    Kisi kisi;
    Dugum *sol;
    Dugum *sag;
    int yukseklik;
    int derinlik;
    Stack *yukseklikS = new Stack(); //Yükseklikleri tutacak stack
};

#endif