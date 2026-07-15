#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> 
#include <ctime>   
#include <fstream> 

using namespace std;

struct MoodData {
    string genre;
    string alasan;
    string daftar_lagu[3]; 
};

void SimpanHistory(string mood, string lagu) {
    ofstream file("history_mood.txt", ios::app); 
    
    if (file.is_open()) {
        // Mengambil waktu saat ini dari sistem
        time_t now = time(0);
        string waktu = ctime(&now);
        waktu.pop_back();
        
        // Format penulisan ke file diperbarui
        file << "[" << waktu << "] Mood: " << mood << " | Rekomendasi Lagu: " << lagu << "\n";
        file.close();
    } else {
        cout << "\n[Peringatan: Gagal membuka atau membuat file history_mood.txt]\n";
    }
}

void TampilkanMenu() {
    cout << "\n=== Mood-Based Music Recommender ===\n";
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
    MoodData database[7] = {
        {"Pop / Dance", "Membantu mempertahankan suasana hati yang ceria.", 
            {"Dua Lipa - Dance The Night", "Pharrell Williams - Happy", "Coldplay - A Sky Full of Stars"}},
        
        {"Acoustic / Ballad", "Membantu menyalurkan emosi dan perasaan.", 
            {"Adele - Someone Like You", "Ed Sheeran - Photograph", "Lewis Capaldi - Someone You Loved"}},
        
        {"Lo-fi / Chill", "Membantu menenangkan pikiran yang kacau.", 
            {"Lofi Girl - chill lofi beats", "Nujabes - Aruarian Dance", "Jinsang - Affection"}},
        
        {"Instrumental / Classical", "Meningkatkan konsentrasi, cocok untuk persiapan kelas Pemrograman Terstruktur di hari Senin 10:40.", 
            {"Hans Zimmer - Interstellar", "Ludovico Einaudi - Experience", "Beethoven - Moonlight Sonata"}},
        
        {"Jazz / Relaxing", "Membantu tubuh dan pikiran lebih rileks.", 
            {"Norah Jones - Don't Know Why", "Miles Davis - Blue in Green", "Bill Evans - Waltz for Debby"}},
        
        {"Phonk / Hard Rock", "Membakar semangat dan energi fisik.", 
            {"Kordhell - Murder In My Mind", "Eminem - Till I Collapse", "Survivor - Eye of the Tiger"}},
        
        {"Ambient / Nature Sounds", "Menurunkan detak jantung agar siap terlelap.", 
            {"Marconi Union - Weightless", "Rain Sounds - Deep Sleep", "Max Richter - Sleep"}}
    };

    string nama_mood[7] = {"Senang", "Sedih", "Stres", "Fokus Belajar", "Capek", "Semangat Olahraga", "Pengantar Tidur"};

    int index = pilihan - 1;
    int random_song_index = rand() % 3;
    
    // UPDATE 3: Menyimpan lagu yang terpilih ke dalam variabel agar bisa dikirim ke fungsi SimpanHistory
    string lagu_terpilih = database[index].daftar_lagu[random_song_index];

    cout << "\n🎧 Rekomendasi Musik:\n";
    cout << "Genre        : " << database[index].genre << endl;
    cout << "Alasan       : " << database[index].alasan << endl;
    cout << "Coba dengar  : " << lagu_terpilih << endl;

    // Memanggil fungsi dengan dua parameter
    SimpanHistory(nama_mood[index], lagu_terpilih);
    
    cout << "=========================================\n";
    cout << "[Info: Data telah dicatat ke history_mood.txt]\n";
}

int main() {
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
            break; 
        }
        else {
            cout << "\nInput tidak valid! Pilih angka 1-8.\n";
        }

        cout << "\nIngin memilih rekomendasi lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih telah menggunakan program ini 🎶\n\n";
    return 0;
}
