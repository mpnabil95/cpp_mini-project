#include <iostream>
using namespace std;

// Fungsi untuk menghitung total belanja
int hitungTotal(int harga[], int jumlah[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total = total + (harga[i] * jumlah[i]);
    }
    return total;
}

// Fungsi untuk menghitung diskon
int hitungDiskon(int total) {
    int diskon = 0;
    if (total >= 100000) {
        diskon = total * 10 / 100; // diskon 10%
    }
    return diskon;
}

// Fungsi menampilkan garis
void garis() {
    cout << "====================================" << endl;
}

int main() {
    int n;
    char ulang;

    do {
        garis();
        cout << "   APLIKASI KASIR TOKO SEDERHANA   " << endl;
        garis();

        cout << "Masukkan jumlah jenis barang: ";
        cin >> n;

        int harga[n];
        int jumlah[n];

        // Input data barang
        for (int i = 0; i < n; i++) {
            cout << "\nBarang ke-" << i + 1 << endl;
            cout << "Harga  : ";
            cin >> harga[i];
            cout << "Jumlah : ";
            cin >> jumlah[i];
        }

        garis();
        cout << "DAFTAR BELANJA" << endl;
        garis();

        for (int i = 0; i < n; i++) {
            cout << "Barang ke-" << i + 1;
            cout << " | Harga: " << harga[i];
            cout << " | Jumlah: " << jumlah[i];
            cout << " | Subtotal: " << harga[i] * jumlah[i] << endl;
        }

        garis();

        int total = hitungTotal(harga, jumlah, n);
        int diskon = hitungDiskon(total);
        int totalBayar = total - diskon;

        cout << "Total Belanja : Rp " << total << endl;
        cout << "Diskon (10%)  : Rp " << diskon << endl;
        cout << "Total Bayar   : Rp " << totalBayar << endl;

        garis();

        // Input uang bayar
        int uangBayar;
        cout << "Masukkan uang bayar: Rp ";
        cin >> uangBayar;

        // Validasi uang bayar
        if (uangBayar < totalBayar) {
            cout << "Uang bayar tidak mencukupi!" << endl;
        } else {
            int kembalian = uangBayar - totalBayar;
            cout << "Kembalian     : Rp " << kembalian << endl;
        }

        garis();
        cout << "Ingin melakukan transaksi lagi? (y/n): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Terima kasih telah berbelanja!" << endl;
    return 0;
}
