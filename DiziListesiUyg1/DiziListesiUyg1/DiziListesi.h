#pragma once
#include "Hata.h"
template<typename T>
class DiziListesi
{
private:int kapasite;
private:int sirasi;
private:T *liste;
public:DiziListesi()
{
	this->kapasite = 10;
	this->sirasi = -1;
	this->liste = new T[kapasite];
}
public:int kapasiteGetir()
{
	return kapasite;
}
public:int elemanSayisi()
{
	return sirasi + 1;
}
public:void Ekle(T eleman)
{
	if (elemanSayisi() == kapasiteGetir()) throw Hata(1);
	liste[++sirasi] = eleman;
}
public:T elemanGetir()
{
	if (elemanSayisi()) return liste[sirasi];
	throw Hata(2);
}
public:T indisdekiEleman(int indis)
{
	if (indis >= elemanSayisi() || indis < 0) throw Hata(3);
	return liste[indis];
}
public:void Sil()
{
	if (elemanSayisi()) sirasi--;
	else throw Hata(2);
}
public:void indisdekiniSil(int indis)
{
	if (indis >= elemanSayisi() || indis < 0) throw Hata(3);
	if (sirasi == indis) Sil();
	else
	{
		for (int i = indis; i < sirasi; i++)
			liste[i] = liste[i + 1];
		sirasi--;
	}
}
};

