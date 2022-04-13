/** 
* @file AvlAgac.cpp
* @description Düğüm oluşturma, oluşan düğümler ile Avl ağacı oluşturma, dengeleme, sağa sola ekleme gibi işlemler burada yapılıyor.
* @course 1.Öğretim B grubu
* @assignment 2
* @date 19.08.2021
* @author Deniz Berfin Taştan / deniz.tastan@ogr.sakarya.edu.tr
**/
#include <iostream>
#include "Dugum.hpp"
#include "AvlAgac.hpp"
using namespace std;
Dugum d1;
Stack s1;
int Avl::max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int Avl::yukseklikHesapla(Dugum *dugum) //Parametre olarak aldığı düğümün yüksekliğini hesaplar.
{
    if (dugum == NULL)
        return 0;
    else
    {
        int solYukseklik = yukseklikHesapla(dugum->sol);
        int sagYukseklik = yukseklikHesapla(dugum->sag);
        if (solYukseklik > sagYukseklik)
        {
            return (solYukseklik + 1);
        }
        else
        {
            return (sagYukseklik + 1);
        }
    }
}
Dugum *Avl::yeniDugum(int boy, string isim, int yas) //Yeni düğüm oluşturur.
{
    Dugum *dugum = new Dugum();
    dugum->kisi.iboy = boy;
    dugum->kisi.isim = isim;
    dugum->kisi.iyas = yas;
    dugum->sol = NULL;
    dugum->sag = NULL;
    dugum->yukseklik = 1;

    return dugum;
}
Dugum *Avl::sagaDon(Dugum *dugum) //Düğümü sağ tarafa gönderir.
{
    Dugum *geciciSol = dugum->sol;//üzerinde bulunduğuz düğümün solundaki değişken için geçiçi değişken
    Dugum *gecici = geciciSol->sag;//üzerinde bulunduğumuz düğüm için geçici değişken

    geciciSol->sag = dugum;
    dugum->sol = gecici;

    dugum->yukseklik = max(yukseklikHesapla(dugum->sol), yukseklikHesapla(dugum->sag)) + 1;
    geciciSol->yukseklik = max(yukseklikHesapla(geciciSol->sol), yukseklikHesapla(geciciSol->sag)) + 1; //Yapılan işlemden sonra tekrar yükseklik hesaplanır.

    return geciciSol;
}
Dugum *Avl::solaDon(Dugum *dugum) //Düğümü sol tarafa gönderir.
{
    Dugum *geciciSag = dugum->sag; //üzerinde bulunduğuz düğümün sağındaki değişken için geçiçi değişken
    Dugum *gecici = geciciSag->sol; //üzerinde bulunduğumuz düğüm için geçici değişken

    geciciSag->sol = dugum;
    dugum->sag = gecici;

    dugum->yukseklik = max(yukseklikHesapla(dugum->sol), yukseklikHesapla(dugum->sag)) + 1;
    geciciSag->yukseklik = max(yukseklikHesapla(geciciSag->sol), yukseklikHesapla(geciciSag->sag)) + 1;//Yapılan işlemden sonra tekrar yükseklik hesaplanır.

    return geciciSag;
}
int Avl::dengele(Dugum *dugum)
{
    if (dugum == NULL)
        return 0;
    return yukseklikHesapla(dugum->sol) - yukseklikHesapla(dugum->sag);
}
Dugum *Avl::ekle(Dugum *dugum, int boy, string isim, int yas)//Ağaca düğüm eklemesi yapar.
{
    if (dugum == NULL) //Eğer düğüm null ise yeni düğüm oluştur.
        return (yeniDugum(boy, isim, yas));
    if (boy < dugum->kisi.iboy)//Eğer dosyadan gelen boy değeri,düğümün boy küçük ise yeni düğümü sol tarafa ekler.
        dugum->sol = ekle(dugum->sol, boy, isim, yas);
    else if (boy > dugum->kisi.iboy)//Eğer dosyadan gelen boy değeri,düğümün boy büyük ise yeni düğümü sağ tarafa ekler.
        dugum->sag = ekle(dugum->sag, boy, isim, yas);
    else//Eğer dosyadan gelen boy değeri,düğümün boyuna eşit ise yeni düğümü sol tarafa ekler.
        dugum->sol = ekle(dugum->sol, boy, isim, yas);

    dugum->yukseklik = 1 + max(yukseklikHesapla(dugum->sol), yukseklikHesapla(dugum->sag)); //Düğümün yeni yüksekliği hesaplanır.
    int denge = dengele(dugum); //İki düğüm arasındaki yükseklik farkını hesaplar.
    
    //İki düğümün arasındaki fark 1 veya -1 ise ağacı dengelemek için düğümleri sağa veya sola gönderir.
    if (denge > 1 && boy < dugum->sol->kisi.iboy) 
        return sagaDon(dugum);
    if (denge > 1 && boy > dugum->sol->kisi.iboy)
    {
        dugum->sol = solaDon(dugum->sol);
        return sagaDon(dugum);
    }
    if (denge < -1 && boy > dugum->sag->kisi.iboy)
        return solaDon(dugum);

    if (denge < -1 && boy < dugum->sag->kisi.iboy)
    {
        dugum->sag = sagaDon(dugum->sag);
        return solaDon(dugum);
    }

    return dugum;
}
void Avl::yazdir(Dugum *kok)
{
    int i;
    for (i = 1; i <= yukseklikHesapla(kok); i++)
        sirala(kok, i);
}
void Avl::sirala(Dugum *kok, int level) //Ağacı level order şekilde sıralar ve ekrana yazar.
{
    if (kok == NULL)
        return;
    if (level == 1)
    {
        cout << kok->kisi.isim << " " << kok->kisi.iyas << " " << kok->kisi.iboy;
        cout << " (Y:";
        kok->yukseklikS->stackYazdir();
        cout<<")" << endl;
    }
    else if (level > 1)
    {
        sirala(kok->sol, level - 1);
        sirala(kok->sag, level - 1);
    }
}
void Avl::stackDoldur(Dugum *kok, int level) //Stack içine atama yapar.
{
    if (kok == NULL)
        return;

    kok->yukseklikS->Push(kok->yukseklik-1); //Düğümün yükseklik değerini yükseklik stack'ine ekler.
    if (level > 1)
    {
        stackDoldur(kok->sol, level - 1);
        stackDoldur(kok->sag, level - 1);
    }
}

