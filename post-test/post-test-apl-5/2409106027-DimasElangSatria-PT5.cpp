#include <iostream>
using namespace std;

struct Workshop {
    string judulworkshop, pemateri, tanggal, linkgrup;
};

struct User {
    string username, password;
};

struct DataProgram {
    Workshop workshop[10];
    int totalWorkshops = 0;
};

User user;
int percobaan = 3;

// Fungsi menampilkan jumlah workshop (pakai pointer)
int jumlahWorkshop(DataProgram* data) {
    return data->totalWorkshops;
}

// Fungsi overloading jumlahWorkshop (pakai dereference)
int jumlahWorkshop(int* total) {
    cout << "Jumlah workshop direncanakan : " << *total << endl;
    return *total;
}

// Fungsi rekursif untuk mencari judul terpanjang 
string cariJudulTerpanjang(DataProgram &data, int indeks, string terpanjang) {
    if (indeks >= data.totalWorkshops) return terpanjang;
    if (data.workshop[indeks].judulworkshop.length() > terpanjang.length()) {
        terpanjang = data.workshop[indeks].judulworkshop;
    }
    return cariJudulTerpanjang(data, indeks + 1, terpanjang);
}

void tampilkanWorkshop(DataProgram* data) {
    if (data->totalWorkshops == 0) {
        cout << "Belum ada Workshop tersedia" << endl;
    } else {
        for (int i = 0; i < data->totalWorkshops; i++) {
            cout << i + 1 << ". "
                << data->workshop[i].judulworkshop << " - "
                << data->workshop[i].pemateri << " - "
                << data->workshop[i].tanggal << " - "
                << data->workshop[i].linkgrup << endl;
        }
    }
}

void tambahWorkshop(DataProgram* data) {
    int i = data->totalWorkshops;
    cout << "Masukkan nama workshop: ";
    getline(cin, data->workshop[i].judulworkshop);
    cout << "Masukkan nama pemateri: ";
    getline(cin, data->workshop[i].pemateri);
    cout << "Masukkan tanggal pelaksanaan: ";
    getline(cin, data->workshop[i].tanggal);
    cout << "Masukkan link grup workshop: ";
    getline(cin, data->workshop[i].linkgrup);
    data->totalWorkshops++;
    cout << "Workshop baru berhasil ditambahkan!" << endl;
}

void updateWorkshop(DataProgram* data) {
    if (data->totalWorkshops == 0) {
        cout << "Workshop tidak ditemukan." << endl;
        return;
    }
    tampilkanWorkshop(data);
    int pilih;
    cout << "Masukkan nomor workshop yang akan diubah: ";
    cin >> pilih;
    cin.ignore();
    if (pilih > 0 && pilih <= data->totalWorkshops) {
        cout << "Masukkan nama Workshop baru: ";
        getline(cin, data->workshop[pilih - 1].judulworkshop);
        cout << "Masukkan nama pemateri baru: ";
        getline(cin, data->workshop[pilih - 1].pemateri);
        cout << "Masukkan tanggal baru: ";
        getline(cin, data->workshop[pilih - 1].tanggal);
        cout << "Masukkan link grup baru: ";
        getline(cin, data->workshop[pilih - 1].linkgrup);
        cout << "Workshop berhasil diubah." << endl;
    } else {
        cout << "Nomor workshop tidak valid." << endl;
    }
}

void hapusWorkshop(DataProgram* data) {
    if (data->totalWorkshops == 0) {
        cout << "Workshop tidak ditemukan." << endl;
        return;
    }
    tampilkanWorkshop(data);
    int input;
    cout << "Masukkan nomor workshop yang akan dihapus: ";
    cin >> input;
    if (input >= 1 && input <= data->totalWorkshops) {
        for (int i = input - 1; i < data->totalWorkshops - 1; i++) {
            data->workshop[i] = data->workshop[i + 1];
        }
        data->totalWorkshops--;
        cout << "Workshop berhasil dihapus." << endl;
    } else {
        cout << "Nomor workshop tidak valid." << endl;
    }
}

void menuAdmin(DataProgram &dataprogram) {
    int pilihan, total;
    do {
        cout << "\n|| ===== MENU ADMIN ===== ||\n";
        cout << "1. Tambah Workshop\n2. Lihat Workshop Tersedia\n3. Update Workshop\n4. Hapus Workshop\n5. Lihat Jumlah Workshop\n6. Lihat Judul Terpanjang\n7. Rencana Jumlah Workshop\n8. Logout\nMasukkan Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tambahWorkshop(&dataprogram); break;
            case 2: tampilkanWorkshop(&dataprogram); break;
            case 3: updateWorkshop(&dataprogram); break;
            case 4: hapusWorkshop(&dataprogram); break;
            case 5:
                cout << "Jumlah workshop saat ini: " << jumlahWorkshop(&dataprogram) << endl;
                break;
            case 6:
                cout << "Judul terpanjang: " << cariJudulTerpanjang(dataprogram, 0, "") << endl;
                break;
            case 7:
                cout << "Masukkan total workshop direncanakan (int): ";
                cin >> total;
                jumlahWorkshop(&total);
                if (jumlahWorkshop(&dataprogram) < total)
                    cout << "Jumlah Workshop Saat Ini Belum Memenuhi Rencana, Silahkan Tambahkan Workshop" << endl;
                else
                    cout << "Jumlah Workshop Saat Ini Memenuhi Rencana" << endl;
                break;
        }
    } while (pilihan != 8);
}

void menuPengguna(DataProgram &dataprogram) {
    int pilihan;
    do {
        cout << "\n|| ===== MENU PENDAFTAR ===== ||\n";
        cout << "1. Lihat Workshop Tersedia\n2. Logout\nPilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tampilkanWorkshop(&dataprogram);
            int pilihanWorkshop;
            cout << "Pilih nomor workshop untuk melihat link grup: ";
            cin >> pilihanWorkshop;
            cin.ignore();
            if (pilihanWorkshop > 0 && pilihanWorkshop <= dataprogram.totalWorkshops) {
                cout << "Link grup untuk " << dataprogram.workshop[pilihanWorkshop - 1].judulworkshop
                    << " adalah: " << dataprogram.workshop[pilihanWorkshop - 1].linkgrup << endl;
                cout << "Silakan join grup untuk mendapat info seputar Workshop." << endl;
            } else {
                cout << "Nomor workshop tidak valid." << endl;
            }
        }
    } while (pilihan != 2);
}

void registerUser() {
    cout << "\n|| ===== REGISTER ===== ||\n";
    cout << "Masukkan username baru : ";
    getline(cin, user.username);
    cout << "Masukkan Password baru : ";
    getline(cin, user.password);
}

bool login(DataProgram &dataprogram) {
    string inputusn, inputpw;
    cout << "\n|| ===== LOGIN ===== ||\n";
    cout << "Masukkan username : ";
    getline(cin, inputusn);
    cout << "Masukkan Password : ";
    getline(cin, inputpw);

    if (inputusn == "dimas" && inputpw == "027") {
        menuAdmin(dataprogram);
        return true;
    } else if (inputusn == user.username && inputpw == user.password) {
        menuPengguna(dataprogram);
        return true;
    } else {
        percobaan--;
        cout << "Login gagal! Sisa percobaan: " << percobaan << endl;
        if (percobaan == 0) {
            cout << "Anda telah gagal login 3 kali. Program dihentikan." << endl;
            exit(0);
        }
        return false;
    }
}

int main() {
    DataProgram dataprogram;
    int pilihan;

    while (true) {
        cout << "\n|| ===== MENU AWAL ===== ||\n";
        cout << "1. Register\n2. Login\n3. Keluar\nPilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: registerUser(); break;
            case 2: login(dataprogram); break;
            case 3:
                cout << "Program dihentikan." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}
