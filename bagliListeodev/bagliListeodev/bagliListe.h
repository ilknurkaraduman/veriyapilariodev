#pragma once
#include"Dugum.h"
template<typename T>
class bagliListe
{
private:Dugum<T> *ilk;
private:Dugum<T> *gecici;
private:Dugum<T> *a;
public:bagliListe()
{
	ilk = NULL;
}
public:void Ekle(T karakter)
{
	Dugum<T> *eklenecek = new Dugum<T>(karakter);
	if (ilk)
	{
		Dugum<T> *son = ilk;
		while (son->sonraki != NULL) son = son->sonraki;
		son->sonraki = eklenecek;
	}
	else ilk = eklenecek;
}
public:void tersCevir()
{
	Dugum<T> *öncekid = NULL;
	Dugum<T> *sonrakid;
	gecici = ilk;
	while (gecici != NULL)
	{
		sonrakid = gecici->sonraki;
		gecici->sonraki = öncekid;
		öncekid = gecici;
		gecici = sonrakid;
	}
	ilk = öncekid;
}
public:void Listele()
{
	int u = 0;
	Dugum<T> *son = ilk;
	while (son != NULL)
	{
		u++;
		cout << son->bilgi;
		son = son->sonraki;
	}
}
public:int Uzunluk()
{
	int u = 0;
	Dugum<T> *son = ilk;
	while (son != NULL)
	{
		u++;
		son = son->sonraki;
	}
	return u;
}
public:void sondanSil()
{
	gecici = ilk;
	while (gecici->sonraki->sonraki != NULL)
	{
		gecici = gecici->sonraki;
	}
	Dugum<T> *cukubik = gecici->sonraki;
	gecici->sonraki = NULL;
}
public:void bastanSil()
{
	if (ilk->sonraki != NULL)
	{
		Dugum<T> *silinecek = ilk;
		ilk = ilk->sonraki;
	}
	else
	{
		ilk = NULL;
	}
}
public:void indisdekiniSil(int indis)
{
	if (indis < 0 || indis >= Uzunluk()) throw Hata(3);
	if (indis == Uzunluk() - 1) Sil();
	else if (indis == 0)
	{
		Dugum<T> *silinecek = ilk;
		ilk = ilk->sonraki;
		delete silinecek;
	}
	else
	{
		Dugum<T> *silinecek;
		Dugum<T> *onceki = ilk;
		int ie = 1;
		while (ie != indis) {
			onceki = onceki->sonraki;
			ie++;
		}
		silinecek = onceki->sonraki;
		onceki->sonraki = onceki->sonraki->sonraki;
		delete silinecek;
	}
}
public:void Sil()
{
	//if (bosMu())throw Hata(2);
	if (Uzunluk() == 1)
	{
		delete ilk;
		ilk = NULL;
	}
	else
	{
		Dugum<T> *son = ilk;
		while (son->sonraki->sonraki != NULL) son = son->sonraki;
		delete son->sonraki;
		son->sonraki = NULL;
	}
}
public:int Bul(T eleman)
{
	if (ilk)
	{
		Dugum<T> *aranacak = ilk;
		int ei = 0;
		/*if (!(aranacak == NULL))
		{
		if (aranacak->bilgi == eleman) return ei;
		ei++;
		aranacak = aranacak->sonraki;
		}*/
		while (aranacak != NULL)
		{
			if (aranacak->bilgi == eleman) return ei;
			ei++;
			aranacak = aranacak->sonraki;
		}throw Hata(4);
	}
	else throw Hata(2);
}
public:void sonaEkle(T eleman)
{
	Dugum<T> *eklenecek = new Dugum<T>(eleman);
	eklenecek->bilgi = eleman;
	eklenecek->sonraki = NULL;
	gecici = ilk;
	while (gecici->sonraki != NULL)
	{
		gecici = gecici->sonraki;
	}
	gecici->sonraki = eklenecek;
}
public:void basaEkle(T eleman)
{
	Dugum<T> *eklenecek = new Dugum<T>(eleman);
	if (ilk)
	{
		eklenecek->bilgi = eleman;
		gecici = ilk;
		eklenecek->sonraki = gecici;
		ilk = eklenecek;
	}
	else ilk = eklenecek;
}
public:void arayaEkle(T eleman,int indis)
{
	Dugum<T> *eklenecek = new Dugum<T>(eleman);
	if (indis<0 || indis>Uzunluk()) throw Hata(3);
	else if (indis == Uzunluk()) Ekle(eleman);
	else if (indis == 0)
	{
		eklenecek->sonraki = ilk;
		ilk = eklenecek;
	}
	else
	{
		int ei = 0;
		Dugum<T> *son = ilk;
		while (ei < indis - 1)
		{
			ei++;
			son = son->sonraki;
		}
		eklenecek->sonraki = son->sonraki;
		son->sonraki = eklenecek;
	}	
}
};
