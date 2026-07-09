#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> // Untuk fungsi rand() dan srand()
#include <ctime>   // Untuk fungsi time()
#include <fstream> // Untuk operasi file I/O (menyimpan ke .txt)

using namespace std;

// Struct yang sudah diperbarui dengan array lagu
struct MoodData {
    string genre;
    string alasan;
    string daftar_lagu[3]; 
};

// Fungsi untuk menyimpan riwayat ke file teks
void SimpanHistory(string mood) {
    ofstream file("history_mood.txt", ios::app); // ios::app agar teks ditambahkan di baris bawahnya, bukan ditimpa
    
    if (file.is_open()) {
        file << "Mood yang dipilih: " << mood << "\n";
        file.close();
    } else {
        cout << "\n[Peringatan: Gagal membuka atau membuat file history_mood.txt]\n";
    }
}

void TampilkanMenu() {
    cout << "\n=== Mood-Based Music Recommender v2.0 ===\n";
    cout << "1. Senang\n";
    cout << "2. Sedih\n";
    cout << "3. Stres\n";
    cout << "4. Fokus Belajar\n";
    cout << "5. Capek\n";
    cout << "6. Semangat Olahraga\n";
    cout << "7. Pengantar Tidur\n";
    cout << "8. (Keluar)\n";
    cout << "Pilih mood anda sekarang (1-8): ";
}

void RekomendasiMusik(int pilihan) {
    // Database musik lengkap dengan 3 lagu acak per kategori
    MoodData database[7] = {
        {"Pop / Dance", "Membantu mempertahankan suasana hati yang ceria.", 
            {"Dua Lipa - Dance The Night", "Pharrell Williams - Happy", "Coldplay - A Sky Full of Stars"}},
        
        {"Acoustic / Ballad", "Membantu menyalurkan emosi dan perasaan.", 
            {"Adele - Someone Like You", "Ed Sheeran - Photograph", "Lewis Capaldi - Someone You Loved"}},
        
        {"Lo-fi / Chill", "Membantu menenangkan pikiran yang kacau.", 
            {"Lofi Girl - chill lofi beats", "Nujabes - Aruarian Dance", "Jinsang - Affection"}},
        
        {"Instrumental / Classical", "Meningkatkan konsentrasi, cocok untuk persiapan kelas Pemrograman Terstruktur di hari Senin 10:40 atau Selasa 07:00.", 
            {"Hans Zimmer - Interstellar", "Ludovico Einaudi - Experience", "Beethoven - Moonlight Sonata"}},
        
        {"Jazz / Relaxing", "Membantu tubuh dan pikiran lebih rileks.", 
            {"Norah Jones - Don't Know Why", "Miles Davis - Blue in Green", "Bill Evans - Waltz for Debby"}},
        
        {"Phonk / Hard Rock", "Membakar semangat dan energi fisik.", 
            {"Kordhell - Murder In My Mind", "Eminem - Till I Collapse", "Survivor - Eye of the Tiger"}},
        
        {"Ambient / Nature Sounds", "Menurunkan detak jantung agar siap terlelap.", 
            {"Marconi Union - Weightless", "Rain Sounds - Deep Sleep", "Max Richter - Sleep"}}
    };

    // Array nama mood untuk mempermudah pencatatan history
    string nama_mood[7] = {"Senang", "Sedih", "Stres", "Fokus Belajar", "Capek", "Semangat Olahraga", "Pengantar Tidur"};

    int index = pilihan - 1;
    
    // Menghasilkan angka acak antara 0, 1, atau 2
    int random_song_index = rand() % 3;

    cout << "\n🎧 Rekomendasi Musik:\n";
    cout << "Genre        : " << database[index].genre << endl;
    cout << "Alasan       : " << database[index].alasan << endl;
    cout << "Coba dengar  : " << database[index].daftar_lagu[random_song_index] << endl;

    // Memanggil fungsi untuk menyimpan data ke file
    SimpanHistory(nama_mood[index]);
    cout << "=========================================\n";
    cout << "[Info: Mood '" << nama_mood[index] << "' telah dicatat ke history_mood.txt]\n";
}

int main() {
    // Inisialisasi seed agar fungsi rand() benar-benar acak berdasarkan waktu saat ini
    srand(time(0)); 

    int pilihan;
    char ulang;

    do {
        TampilkanMenu();
        cin >> pilihan;

        if(cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "\nInput tidak valid! Harap masukkan angka.\n";
            ulang = 'y';
            continue; 
        }

        if (pilihan >= 1 && pilihan <= 7) {
            RekomendasiMusik(pilihan);
        }
        else if (pilihan == 8) {
            cout << "\nTerima kasih telah menggunakan program ini 🎶\n";
            break; 
        }
        else {
            cout << "\nInput tidak valid! Pilih angka 1-8.\n";
        }

        cout << "\nIngin memilih rekomendasi lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram selesai.\n";
    return 0;
}