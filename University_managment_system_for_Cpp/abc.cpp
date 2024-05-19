#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include "UniversityManagementSystem.h"

using namespace std;

void printBoxedText(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    cout << "+" << string(width, '-') << "+" << endl;
    cout << "|" << string(padding, ' ') << text << string(width - padding - text.length(), ' ') << "|" << endl;
    cout << "+" << string(width, '-') << "+" << endl;
}

void displayMainMenu() {
    system("CLS");
    cout << endl;
    printBoxedText("Universite Yonetim Sistemi", 40);
    cout << endl;
    printBoxedText("1. Ogrenci Islemleri", 40);
    printBoxedText("2. Ogretmen Islemleri", 40);
    printBoxedText("3. Bolum Islemleri", 40);
    printBoxedText("4. Ders Islemleri", 40);
    printBoxedText("5. Çikis", 40);
    cout << endl;
    cout << "Seciminiz: ";
}

void displayStudentMenu() {
    system("CLS");
    cout << endl;
    printBoxedText("Ogrenci Islemleri Menusu", 40);
    cout << endl;
    printBoxedText("1. Ogrenci Bilgileri Ekle", 40);
    printBoxedText("2. Ogrencileri Goster", 40);
    printBoxedText("3. Ana Menuye Don", 40);
    cout << endl;
    cout << "Seciminiz: ";
}

void displayTeacherMenu() {
    system("CLS");
    cout << endl;
    printBoxedText("Ogretmen Islemleri Menusu", 40);
    cout << endl;
    printBoxedText("1. Ogretmen Bilgileri Ekle", 40);
    printBoxedText("2. Ogretmenleri Goster", 40);
    printBoxedText("3. Ana Menüye Don", 40);
    cout << endl;
    cout << "Seciminiz: ";
}

void displayDepartmentMenu() {
    system("CLS");
    cout << endl;
    printBoxedText("Bolum Islemleri Menusu", 40);
    cout << endl;
    printBoxedText("1. Bolum Ekle", 40);
    printBoxedText("2. Bolumleri Goster", 40);
    printBoxedText("3. Ana Menuye Don", 40);
    cout << endl;
    cout << "Seciminiz: ";
}

void displayCourseMenu() {
    system("CLS");
    cout << endl;
    printBoxedText("Ders Islemleri Menüsü", 40);
    cout << endl;
    printBoxedText("1. Ders Bilgileri Ekle", 40);
    printBoxedText("2. Dersleri Goster", 40);
    printBoxedText("3. Ana Menuye Don", 40);
    cout << endl;
    cout << "Seciminiz: ";
}

int main() {
    UniversityYonetimSistemi sistem;

    int secim;
    do {
        displayMainMenu();
        secim = _getch() - '0'; 

        switch (secim) {
        case 1: {
            
            int ogrenciSecim;
            do {
                displayStudentMenu();
                ogrenciSecim = _getch() - '0'; 

                switch (ogrenciSecim) {
                case 1:
                    sistem.ogrenciEkle();
                    break;
                case 2:
                    sistem.ogrencileriGoster();
                    cout << "Ana menuye donmek için 0 tusuna basin...";
                    while (_getch() != '0'); 
                    break;
                case 3:
                    break;
                default:
                    cout << "Geçersiz secim! Lutfen tekrar deneyin." << endl;
                }
            } while (ogrenciSecim != 3);
            break;
        }
        case 2: {
            
            int ogretmenSecim;
            do {
                displayTeacherMenu();
                ogretmenSecim = _getch() - '0'; 

                switch (ogretmenSecim) {
                case 1: {
                    string ad;
                    cout << "Ogretmen adı: ";
                    cin >> ad;
                    sistem.ogretmenAdiAta(ad);
                    break;
                }
                case 2:
                    sistem.ogretmenleriGoster();
                    cout << "Ana menuye donmek icin 0 tusuna basin...";
                    while (_getch() != '0');
                    break;
                case 3:
                    break;
                default:
                    cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
                }
            } while (ogretmenSecim != 3);
            break;
        }
        case 3: {
            
            int bolumSecim;
            do {
                displayDepartmentMenu();
                bolumSecim = _getch() - '0'; 

                switch (bolumSecim) {
                case 1:
                    sistem.bolumEkle();
                    break;
                case 2:
                    sistem.bolumleriGoster();
                    cout << "Ana menüye dönmek için 0 tuşuna basın...";
                    while (_getch() != '0'); 
                    break;
                case 3:
                    break;
                default:
                    cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
                }
            } while (bolumSecim != 3);
            break;
        }
        case 4: {
            
            int dersSecim;
            do {
                displayCourseMenu();
                dersSecim = _getch()
                    - '0'; 

                switch (dersSecim) {
                case 1:
                    sistem.dersEkle();
                    break;
                case 2:
                    sistem.dersleriGoster();
                    cout << "Ana menuye donmek icin 0 tuşuna basin...";
                    while (_getch() != '0');
                    break;
                case 3:
                    break;
                default:
                    cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
                }
            } while (dersSecim != 3);
            break;
        }
        case 5:
            cout << "Programdan cikiliyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
        }
    } while (secim != 5);

    return 0;
}
