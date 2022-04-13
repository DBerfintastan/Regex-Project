/** 
* @file Stack.cpp
* @description Stack oluşturmak için gerekli işlemler burada yapılıyor.
* @course 1.Öğretim B grubu
* @assignment 2
* @date 24.08.2021
* @author Deniz Berfin Taştan / deniz.tastan@ogr.sakarya.edu.tr
**/

#include <iostream>
#include "Dugum.hpp"
#include "Stack.hpp"
using namespace std;
Stack::Stack()
{
    elemanlar = NULL;
    ilk = -1;
    boyut= 0;
    kapasite = 0;
}
void Stack::Reserve(int kapasite)
{
    int *tmp = new int[kapasite];
    for (int j = 0; j < boyut; j++)
        tmp[j] = elemanlar[j];
    if (elemanlar != NULL)
        delete[] elemanlar;
    elemanlar = tmp;
    this->kapasite = kapasite;
}
void Stack::Push(int obj) //STack'e eleman ekler.
{
    if (boyut== kapasite)
    {
        Reserve(max(1, 2 * kapasite));
    }
    ilk++;
    elemanlar[ilk] = obj;
    boyut++;
}
void Stack::Pop() //Stack'ten eleman siler.
{
    if (ilk == -1)
        return;
    cout << elemanlar[boyut-1]<<" ";
    ilk--;
    boyut--;
}
void Stack::stackYazdir() //Pop fonksiyonunu kullanarak stack'ten çıkarılan elemanları ekrana yazarak çalışmaya devam eder.
{
    for (int i = boyut- 1; i >= 0; i--)
    {
        Pop();
    }
}
Stack::~Stack()
{
    if (elemanlar != NULL)
        delete[] elemanlar;
    elemanlar = NULL;
}