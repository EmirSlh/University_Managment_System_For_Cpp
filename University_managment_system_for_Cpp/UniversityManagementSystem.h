#ifndef UNIVERSITYMANAGEMENTSYSTEM_H
#define UNIVERSITYMANAGEMENTSYSTEM_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>



using namespace std;


class UniversityYonetimSistemi {
private:
    string ogrenciAdi;
    string ogretmenAdi;
    string dersAdi;
    
    static int ogrenciSayisi;

public:
    UniversityYonetimSistemi(string ogrenciAdi = "", string ogretmenAdi = "", string dersAdi = "");
    ~UniversityYonetimSistemi();

    void ogrencileriGoster();
    void ogrenciEkle();
    void ogretmenAdiAta(const string& ad);
  
    void bolumEkle();
    void dersleriGoster();
    void bolumleriGoster();
    void dersEkle();
    void ogretmenleriGoster();
   

    UniversityYonetimSistemi operator+(const UniversityYonetimSistemi& other);
    UniversityYonetimSistemi operator-(const UniversityYonetimSistemi& other);
    bool operator==(const UniversityYonetimSistemi& other) const;
};

#endif
