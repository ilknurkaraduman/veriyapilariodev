#include "stdafx.h"
#include "DiziListesi.h"
#include <conio.h>
#include <iostream>
#include "Hata.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	char secim;
	int eleman, indis;
	DiziListesi<int> *diziListesi = new DiziListesi<int>();
	do
	{
		system("cls");
		cout << "..ÝÞLEMLER" << endl;
		cout << "..1-Eleman Sayýsý" << endl;
		cout << "..2-Kapasite" << endl;
		cout << "..3-Eleman Ekle" << endl;
		cout << "..4-Eleman Getir" << endl;
		cout << "..5-Ýndis ile Eleman Getir" << endl;
		cout << "..6-Eleman Sil" << endl;
		cout << "..7-Ýndis ile Eleman Sil" << endl;
		cout << "..E-Çýkýþ" << endl;
		cout << ".. Seçiminiz :::"; cin >> secim;
		system("cls");
		try
		{
			switch (secim)
			{
			case '1':cout << "Eleman Sayýsý:" <<
				diziListesi->elemanSayisi() << endl;
				break;
			case '2':cout << "Listesinin Kapasitesi:" <<
				diziListesi->kapasiteGetir() << endl;
				break;
			case '3':
				cout << "Ekelenecek deðer: ";
				cin >> eleman;
				diziListesi->Ekle(eleman);
				break;
			case '4':cout << "Son eklenen deðer : " <<
				diziListesi->elemanGetir() << endl;
				break;
			case '5':
				cout << "Elemanýn indisi:";
				cin >> indis;
				cout << "Ýndisdeki Eleman : " <<
					diziListesi->indisdekiEleman(indis) << endl;
				break;
			case '6':
				diziListesi->Sil();
				cout << "Eleman Silindi" << endl;
				break;
			case '7':
				cout << "Elemanýn indisi:";
				cin >> indis;
				diziListesi->indisdekiniSil(indis);
				cout << "Eleman Silindi" << endl;
				break;
			case 'E': break;
			default:
				cout << "Hatalý Seçim" << endl;
				break;
			}
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
		if (secim != 'E')
		{
			cout << "Devam Etmek için Bir tuþa basýnýz...";
			_getch();
		}
	} while (secim != 'E');
    return 0;
}

