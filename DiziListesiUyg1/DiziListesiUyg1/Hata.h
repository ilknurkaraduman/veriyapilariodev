#pragma once
#include<iostream>
using namespace std;
class Hata
{
private:int hataKodu;
public:Hata(int hataKodu)
{
	this->hataKodu = hataKodu;
}
public:void Mesaj()
{
	switch (hataKodu)
	{
	case 1:cout << "Liste Dolu" << endl; break;
	case 2:cout << "Liste Boþ" << endl; break;
	case 3:cout << "Ýndis aralýk dýþýnda" << endl; break;
	default:
		cout << "Bilinmeyen Hata";
		break;
	}
}
public:void Mesaj(int hataKodu)
{
	switch (hataKodu)
	{
	case 1:cout << "Liste Dolu" << endl; break;
	case 2:cout << "Liste Boþ" << endl; break;
	case 3:cout << "Ýndis aralýk dýþýnda" << endl; break;
	default:
		cout << "Bilinmeyen Hata";
		break;
	}
}
};