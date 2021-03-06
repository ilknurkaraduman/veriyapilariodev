/***********************************************************************************************************
**                                         SAKARYA ÜNİVERSİTESİ                                           **
**                                BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ                               **
**                                 BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ BÖLÜMÜ                                 **
**                                         VERİ YAPILARI DERSİ                                            **
**                                         2017-2018 GÜZ DÖNEMİ                                           **
**                                                                                                        **
**                                ÖDEV NUMARASI..........: 1                                              **
**                                ÖĞRENCİ ADI............: İLKNUR KARADUMAN                               **
**                                ÖĞRENCİ NUMARASI.......: b161200040                                     **
***********************************************************************************************************/

#include "stdafx.h"
#include "stdafx.h"
#include<iostream>
#include <conio.h>
#include <locale.h>
#include"bagliListe.h"
#include "Hata.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Turkish");
	bagliListe<char> *Liste = new bagliListe<char>();
	int secim;
	char eleman;
	int h = 0, b = 0, x = 0, ha = 0, bo = 0, indis;
	cout << "Sonsuz Uzunlukta Bir Metin Giriniz: ";
	char karakter;
	int harf = 0, bosluk = 0;
	do
	{
		karakter = _getche();
		if (karakter != ' ') harf++;
		else bosluk++;
		Liste->Ekle(karakter);
	} while (!(karakter == '\r'));
	Liste->sondanSil();
	system("cls");
	do {
		cout << "..İŞLEMLER" << endl;
		cout << "..1-METİN DEĞİŞTİRME" << endl;
		cout << "..2-METNİN KARAKTER SAYISI" << endl;
		cout << "..3-METNİ TERSİNE ÇEVİRME" << endl;
		cout << "..4-METİN İÇİNDE DEĞER ARAMA" << endl;
		cout << "..5-METNİN ÖNÜNE EKLEME" << endl;
		cout << "..6-METNİN SONUNA EKLEME" << endl;
		cout << "..7-METNİN İÇİNE EKLEME" << endl;
		cout << "..99-Çıkış" << endl;
		cout << "::: Seçiminiz :::";
		cin >> secim;
		system("cls");
	try
	{ 
		switch (secim)
		{
		case 1:
			cout << "Yeni metni giriniz: ";
			char yenimetin;
			for (int i = -3; i <= Liste->Uzunluk(); i++)
			{
				Liste->Sil();
			}
			do
			{
				yenimetin = _getche();
				if (yenimetin != ' ') h++;
				else b++;
				Liste->Ekle(yenimetin);
				x++;
			} while (!(yenimetin == '\r'));
			Liste->sondanSil();
			system("cls");
			Liste->Listele();
			cout << endl << "Metin Değiştirildi..." << endl;
			break;
		case 2:
			cout << "Metnin Karakter Sayısı(bosluklar dahildir): ";
			Liste->Uzunluk();
			if (x == 0)
			{
				cout << (harf - 1) + bosluk << endl;
			}
			if (x > 0)
			{
				cout << (h - 1) + b << endl;
				x++;
			}
			break;
		case 3:
			Liste->tersCevir();
			Liste->Listele();
			cout << endl << "Metin Tersine Çevrildi..." << endl;
			break;
		case 4:
			cout << "Aranan değer: ";
			cin >> eleman;
			cout << "Aranan değer indisi: ";
			cout << Liste->Bul(eleman) + 1 << endl; //bosluklar dahil
			break;
		case 5:
			cout << "Eklenecek Metin: ";
			char basaeklenen;
			do
			{
				basaeklenen = _getche();
				if (basaeklenen != ' ')ha++;
				else bo++;
				Liste->basaEkle(basaeklenen);
			} while (!(basaeklenen == '\r'));
			Liste->bastanSil();
			system("cls");
			Liste->Listele();
			cout << endl << "Metin Eklendi..." << endl;
			break;
		case 6:
			cout << "Eklenecek Metin: ";
			char sonaeklenen;
			do
			{
				sonaeklenen = _getche();
				Liste->sonaEkle(sonaeklenen);
			} while (!(sonaeklenen == '\r'));
			Liste->sondanSil();
			system("cls");
			Liste->Listele();
			cout << endl << "Metin Eklendi..." << endl;
			break;
		case 7:
			cout << "Hangi İndise Eklensin?: ";
			cin >> indis;
			cout << "Eklenecek Metin: ";
			char arayaeklenen;
			do
			{
				arayaeklenen = _getche();
				if (arayaeklenen != ' ')ha++;
				else bo++;
				Liste->arayaEkle(arayaeklenen, indis-1);
				indis++;
			} while (!(arayaeklenen == '\r'));
			Liste->indisdekiniSil(indis-2);
			system("cls");
			Liste->Listele();
			cout << endl << "Metin Eklendi..." << endl;
			break;
		case 99: break;
		default:
			cout << "Hatalı Seçim" << endl;
			break;
		}
	}
	catch (Hata h)
	{
		h.Mesaj();
	}
		system("pause");
		system("cls");
	} while (secim != 99);
	system("pause");
    return 0;
}

