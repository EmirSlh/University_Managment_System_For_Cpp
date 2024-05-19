#include "UniversityManagementSystem.h"

int UniversityYonetimSistemi::ogrenciSayisi = 0;

UniversityYonetimSistemi::UniversityYonetimSistemi(string ogrenciAdi, string ogretmenAdi, string dersAdi)
    : ogrenciAdi(ogrenciAdi), ogretmenAdi(ogretmenAdi), dersAdi(dersAdi) {
    ogrenciSayisi++;
}

UniversityYonetimSistemi::~UniversityYonetimSistemi() {
    ogrenciSayisi--;
}



void UniversityYonetimSistemi::ogrenciEkle() {
    string ogrenciAdi, ogrenciSoyadi, bolum, secilenBolum, ogrenciNo;
    int ogrenciSayisi = 0;

    cout << "Öðrencinin adýný girin: ";
    cin >> ogrenciAdi;

    cout << "Öðrencinin soyadýný girin: ";
    cin >> ogrenciSoyadi;

    cout << "Öðrencinin okul numarasýný girin: ";
    cin >> ogrenciNo;

    
    ifstream bolumlerDosya("bolumler.txt");
    if (!bolumlerDosya.is_open()) {
        cerr << "Bölümler dosyasý açýlamadý!" << endl;
        return;
    }

    cout << "Mevcut bölümler:" << endl;
    vector<string> bolumler;
    int bolumNo = 1;
    while (getline(bolumlerDosya, bolum)) {
        cout << bolumNo << ". " << bolum << endl;
        bolumler.push_back(bolum); 
        bolumNo++;
    }
    bolumlerDosya.close(); 

    int secilenBolumNo;
    cout << "Hangi bölümde okuyorsunuz? (Numara olarak seçin): ";
    cin >> secilenBolumNo;
    secilenBolum = bolumler[secilenBolumNo - 1];

    
    ifstream derslerDosya(secilenBolum + ".txt");
    if (!derslerDosya.is_open()) {
        cerr << "Dersler dosyasý açýlamadý!" << endl;
        return;
    }

    cout << "Mevcut dersler:" << endl;
    vector<string> dersler;
    string ders;
    int dersNo = 1;
    while (getline(derslerDosya, ders)) {
        if (ders.find("Ders Adý:") != string::npos) {
            cout << dersNo << ". " << ders.substr(10) << endl;
            dersler.push_back(ders.substr(10)); 
            dersNo++;
        }
    }
    derslerDosya.close(); 

   
    cout << "Hangi dersleri almak istiyorsunuz? (Numara olarak seçin, birden fazla ders için boþlukla ayýrýn): ";
    string secilenDersler;
    cin.ignore(); 
    getline(cin, secilenDersler);

   
    string secilenDerslerIsimler;
    for (char c : secilenDersler) {
        if (isdigit(c)) {
            int dersNo = c - '0';
            if (dersNo >= 1 && dersNo <= dersler.size()) {
                secilenDerslerIsimler += dersler[dersNo - 1];
                secilenDerslerIsimler += " ";
            }
        }
    }
    
    
    ofstream ogrenciDosya(secilenBolum + "_ogrenciler.txt", ios::app);
    if (ogrenciDosya.is_open()) {
        ogrenciDosya << "Ad: " << ogrenciAdi << endl;
        ogrenciDosya << "Soyad: " << ogrenciSoyadi << endl;
        ogrenciDosya << "Okul Numarasý: " << ogrenciNo << endl;
        ogrenciDosya << "Bölüm: " << secilenBolum << endl;
        ogrenciDosya << "Aldýðý Dersler: " << secilenDerslerIsimler << endl;
        ogrenciDosya << "--------------------" << endl;
        cout << "Öðrenci bilgileri dosyaya kaydedildi." << endl;
        
        ogrenciDosya.close(); 
    }
    else {
        cerr << "Öðrenci dosyasý açýlamadý!" << endl;
    }
}


void UniversityYonetimSistemi::ogretmenAdiAta(const string& ad) {
    ogretmenAdi = ad;
    string bolum;
    cout << "Hangi bölümde eðitim veriyor? ";
    cin >> bolum;

    
    ofstream dosya("ogretmenler.txt", ios::app); 
    if (dosya.is_open()) {
        dosya << "Öðretmen Adý: " << ogretmenAdi << ", Girdiði bölümü: " << bolum << endl;
        cout << "Ogretmen bilgileri dosyaya kaydedildi." << endl;
        dosya.close(); 
    }
    else {
        cerr << "Dosya açýlamadý!" << endl;
    }
}
void UniversityYonetimSistemi::bolumEkle() {
    string bolumAdi;
    cout << "Bölüm adý: ";
    cin >> bolumAdi;

    
    ofstream dosya("bolumler.txt", ios::app); 
    if (dosya.is_open()) {
        dosya << bolumAdi << endl;
        cout << "Bölüm bilgileri dosyaya kaydedildi." << endl;
        dosya.close(); 
    }
    else {
        cerr << "Dosya açýlamadý!" << endl;
    }
}




void UniversityYonetimSistemi::dersleriGoster() {
    string bolum;
    ifstream bolumlerDosya("bolumler.txt");
    if (!bolumlerDosya.is_open()) {
        cerr << "Bölümler dosyasý açýlamadý!" << endl;
        return;
    }

    while (getline(bolumlerDosya, bolum)) {
        ifstream derslerDosya(bolum + ".txt");
        if (!derslerDosya.is_open()) {
            cerr << bolum << " bölümü için dersler dosyasý açýlamadý!" << endl;
            continue;
        }

        cout << "Dersler (" << bolum << "):" << endl;
        string ders;
        while (getline(derslerDosya, ders)) {
            if (ders.find("Ders Adý:") != string::npos) {
                cout << ders.substr(10) << endl;
            }
        }
        derslerDosya.close();
    }
    bolumlerDosya.close();
}
void UniversityYonetimSistemi::bolumleriGoster() {
    string bolum;
    ifstream bolumlerDosya("bolumler.txt");
    if (!bolumlerDosya.is_open()) {
        cerr << "Bölümler dosyasý açýlamadý!" << endl;
        return;
    }
    cout << "Mevcut bölümler:" << endl;
    while (getline(bolumlerDosya, bolum)) {
        cout << bolum << endl;
    }
    bolumlerDosya.close();
}



void UniversityYonetimSistemi::dersEkle() {
    ifstream bolumlerDosya("bolumler.txt");
    if (!bolumlerDosya.is_open()) {
        cerr << "Lütfen önce bir bölüm ekleyin!" << endl;
        return;
    }

    cout << "Mevcut bölümler:" << endl;
    vector<string> bolumler;
    string bolum;
    int bolumNo = 1;
    while (getline(bolumlerDosya, bolum)) {
        cout << bolumNo << ". " << bolum << endl;
        bolumler.push_back(bolum); 
        bolumNo++;
    }

    int secilenBolumNo;
    cout << "Hangi bölüme ders eklemek istiyorsunuz? (Numara olarak seçin): ";
    cin >> secilenBolumNo;

   
    string secilenBolum = bolumler[secilenBolumNo - 1];

    
    bolumlerDosya.close();

   
    ofstream derslerDosya(secilenBolum + ".txt", ios::app); 

    
    ifstream ogretmenDosya("ogretmenler.txt");
    if (!ogretmenDosya.is_open()) {
        cerr << "Öðretmenler dosyasý açýlamadý!" << endl;
        return;
    }

    vector<string> ogretmenler;
    string ogretmenAdi;
    while (getline(ogretmenDosya, ogretmenAdi)) {
        ogretmenler.push_back(ogretmenAdi); 
    }

    ogretmenDosya.close(); 

    string secilenDers;
    cout << "Ders adý: ";
    cin >> secilenDers;

   
    cout << "Öðretmeni seçin:" << endl;
    for (size_t i = 0; i < ogretmenler.size(); ++i) {
        cout << i + 1 << ". " << ogretmenler[i] << endl;
    }

    int secilenOgretmenNo;
    cout << "Numara olarak seçin: ";
    cin >> secilenOgretmenNo;

    string secilenOgretmen = ogretmenler[secilenOgretmenNo - 1];

   
    derslerDosya << "Ders Adý: " << secilenDers << endl;
    derslerDosya << "Öðretmen: " << secilenOgretmen << endl;
    derslerDosya << "--------------------" << endl; 

    cout << "Dersler dosyaya kaydedildi." << endl;
    derslerDosya.close(); 
}
void UniversityYonetimSistemi::ogrencileriGoster() {
    string bolum;
    ifstream bolumlerDosya("bolumler.txt");
    if (!bolumlerDosya.is_open()) {
        cerr << "Bölümler dosyasý açýlamadý!" << endl;
        return;
    }

    while (getline(bolumlerDosya, bolum)) {
        ifstream ogrencilerDosya(bolum + "_ogrenciler.txt");
        if (!ogrencilerDosya.is_open()) {
            cerr << bolum << " bölümü için öðrenciler dosyasý açýlamadý!" << endl;
            continue;
        }

        cout << "Öðrenciler (" << bolum << "):" << endl;
        string ogrenci;
        while (getline(ogrencilerDosya, ogrenci)) {
            cout << ogrenci << endl;
        }
        ogrencilerDosya.close();
    }
    bolumlerDosya.close();
}



void UniversityYonetimSistemi::ogretmenleriGoster() {
    string bilgi;
    ifstream dosya("ogretmenler.txt");
    if (!dosya.is_open()) {
        cerr << "Öðretmenler dosyasý açýlamadý!" << endl;
        return;
    }
    cout << "Mevcut öðretmenler:" << endl;
    while (getline(dosya, bilgi)) {
        cout << bilgi << endl;
    }
    dosya.close();
}



UniversityYonetimSistemi UniversityYonetimSistemi::operator+(const UniversityYonetimSistemi& other) {
    UniversityYonetimSistemi yeni;
    
    return yeni;
}

UniversityYonetimSistemi UniversityYonetimSistemi::operator-(const UniversityYonetimSistemi& other) {
    UniversityYonetimSistemi yeni;
    
    return yeni;
}

bool UniversityYonetimSistemi::operator==(const UniversityYonetimSistemi& other) const {
   
    return false;
}
