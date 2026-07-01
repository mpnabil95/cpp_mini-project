#include <iostream>
using namespace std;

void garis() {
    cout << "-----------------------------\n";
}

void MenuKendaraan() {
    garis();
    cout << "JENIS KENDARAAN\n";
    garis();
    cout << "1. Motor Kecil\n";
    cout << "2. Motor Besar\n";
    cout << "3. Mobil Kecil\n";
    cout << "4. Mobil Besar\n";
    garis();
}

int harga(int jenis) {
    if (jenis == 1) {
        return 15000;
    } else if (jenis == 2) {
        return 20000;
    } else if (jenis == 3) {
        return 30000;
    } else if (jenis == 4) {
        return 50000;
    } else {
        return 0;
    }
}

    string nama[10];
    string hari[10];
    string jam[10];
    int jenis[10];
    int total[10];
    int DataKe = 0;
    char ulang;

int main() {

    cout << "==================================\n";
    cout << "  PROGRAM BOOKING CUCI KENDARAAN " << endl;
    cout << "==================================\n";

    do {
        MenuKendaraan();

        cout << "Nama Pelanggan : ";
        cin >> nama[DataKe];

        cout << "Pilih Jenis Kendaraan (1-4) : ";
        cin >> jenis[DataKe];

        cout << "Hari Booking : ";
        cin >> hari[DataKe];

        cout << "Jam Booking (contoh 15.30) : ";
        cin >> jam[DataKe];

        total[DataKe] = harga(jenis[DataKe]);

        cout << "Total Biaya : Rp " << total[DataKe] << endl;

        DataKe++;

        cout << "\nTambah booking lagi? (y/t) : ";
        cin >> ulang;3
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\n===== DATA BOOKING CUCI KENDARAAN =====\n";
    for (int i = 0; i < DataKe; i++) {
        garis();
        cout << "Nama Pelanggan : " << nama[i] << endl;

        if (jenis[i] == 1)
            cout << "Jenis Kendaraan: Motor Kecil\n";
        else if (jenis[i] == 2)
            cout << "Jenis Kendaraan: Motor Besar\n";
        else if (jenis[i] == 3)
            cout << "Jenis Kendaraan: Mobil Kecil\n";
        else if (jenis[i] == 4)
            cout << "Jenis Kendaraan: Mobil Besar\n";
        else
            cout << "Jenis Kendaraan: Tidak Diketahui\n";

        cout << "Hari Booking   : " << hari[i] << endl;
        cout << "Jam Booking    : " << jam[i] << endl;
        cout << "Total Bayar    : Rp " << total[i] << endl;
    }
    garis();
    cout << "Terima kasih telah melakukan booking kendaraan😁😁\n";

    return 0;
}
