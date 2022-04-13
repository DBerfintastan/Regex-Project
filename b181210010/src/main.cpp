/** 
* @file main.cpp
* @description Dosya okuma, bölme, dosyadan veri atama, ağaç yazdırma işlevleri burada yapılıyor.
* @course 1.Öğretim B grubu
* @assignment 2
* @date 19.08.2021
* @author Deniz Berfin Taştan / deniz.tastan@ogr.sakarya.edu.tr
**/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "AvlAgac.hpp"
int main()
{
    ifstream dosyaOku("doc/Kisiler.txt");
    if (dosyaOku.is_open())
    {
        Avl avl;
        Dugum d1;
        Stack s1;
        while (!dosyaOku.eof())
        {
            getline(dosyaOku, d1.kisi.isim, '#');
            getline(dosyaOku, d1.kisi.yas, '#');
            getline(dosyaOku, d1.kisi.boy, '\n'); //Karakterlere göre dosyadan okunan verileri böldüm.
            d1.kisi.iboy = stoi(d1.kisi.boy);
            d1.kisi.iyas = stoi(d1.kisi.yas); //string değerleri integer'a çevirdim.
            avl.kok = avl.ekle(avl.kok, d1.kisi.iboy, d1.kisi.isim, d1.kisi.iyas); //düğüm oluşturup dosyadan okunan verileri düğüme atadım.
            avl.stackDoldur(avl.kok,avl.kok->yukseklik); //Her ekleme yapıldığında stack'e yükseklik ataması yaptım.
        }

        cout << "Level Order: " << endl;
        avl.yazdir(avl.kok); //Oluşan ağacı level order olarak yazdırdım.

        dosyaOku.close();
    }
}