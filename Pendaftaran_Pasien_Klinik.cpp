#include <iostream>
using namespace std;

int HitungBiaya(int layanan) {
    int biaya;

    if (layanan == 1) {
        biaya = 50000; // Biaya pemeriksaan umum
    } else if (layanan == 2) {
        biaya = 75000; // Biaya pemeriksaan gigi
    } else if (layanan == 3) {
        biaya = 100000; // Biaya pemeriksaan spesialis
    } else {
        biaya = 0; 
    }

    return biaya;
}

void garis() {
    cout << "=====================================" << endl;
}

void TampilkanLayanan() {
    garis();
    cout << "      DAFTAR LAYANAN KLINIK    " << endl;
    garis();
    cout << "1. Pemeriksaan Umum" << endl;
    cout << "2. Pemeriksaan Gigi" << endl;
    cout << "3. Pemeriksaan Spesialis" << endl;
    garis();
}

string nama[10], jk[10];
int umur[10], layanan[10], biaya[10];
int JumlahPasien;
char ulang;

int main() {
    garis();
    cout << "  PROGRAM PENDAFTARAN PASIEN KLINIK " << endl;
    garis();

    do {
        cout << "Masukkan jumlah pasien yang mendaftar : ";
        cin >> JumlahPasien;

        for (int i = 0; i < JumlahPasien; i++) {
            cout << endl;
            cout << "Pasien ke-" << i + 1 << endl;

            cout << "Nama Pasien        : ";
            cin >> nama[i];

            cout << "Umur               : ";
            cin >> umur[i];

            cout << "Jenis Kelamin (L/P): ";
            cin >> jk[i];

            TampilkanLayanan();

            cout << "Pilih jenis layanan (1-3): ";
            cin >> layanan[i];

            biaya[i] = HitungBiaya(layanan[i]);
        }

        cout << endl;
        garis();
        cout << "       DATA PASIEN TERDAFTAR        " << endl;
        garis();

        for (int i = 0; i < JumlahPasien; i++) {
            cout << endl;
            cout << "Pasien ke-" << i + 1 << endl;
            cout << "Nama          : " << nama[i] << endl;
            cout << "Umur          : " << umur[i] << " tahun" << endl;
            cout << "Jenis Kelamin : " << jk[i] << endl;
            cout << "Biaya         : Rp " << biaya[i] << endl;
        }

        cout << endl;
        cout << "Ingin mendaftarkan pasien lagi? (Y/T): ";
        cin >> ulang;

    } while (ulang == 'Y' || ulang == 'y');

    cout << endl;
    cout << "Terima kasih telah melakukan pendaftaran klinik😊😊" << endl;

    return 0;
}
