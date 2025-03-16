#include <iostream>
using namespace std;

int main() {
    string workshops[10], pemateri[10], tanggal[10],linkgrup[10];
    int totalWorkshops = 0;
    string username, password;
    int percobaan = 0;
    
    while (true) {
        if (percobaan >= 3) {
            cout << "Terlalu banyak percobaan login. Program berhenti.\n";
            break;
        }

        cout << "\n|| ===== LOGIN ===== ||\n";
        cout << "Masukkan username : ";
        getline(cin, username);
        cout << "Masukkan password : ";
        getline(cin, password);
        
        if (username == "dimas" && password == "027") {
            int pilihan;
            do {
                cout << "\n|| ===== Menu Admin ===== ||\n";
                cout << "1. Tambah Workshop\n2. Lihat Workshop Tersedia\n3. Update Workshop\n4. Hapus Workshop\n5. Logout\n6. Keluar\nMasukkan Pilihan: ";
                cin >> pilihan;
                cin.ignore();
                cout << "";
                
                if (pilihan == 1 && totalWorkshops < 10) {
                    cout << "Masukkan nama workshop: ";
                    getline(cin, workshops[totalWorkshops]);
                    cout << "Masukkan nama pemateri: ";
                    getline(cin, pemateri[totalWorkshops]);
                    cout << "Masukkan tanggal pelaksanaan: ";
                    getline(cin, tanggal[totalWorkshops]);
                    cout << "Masukkan link grup workshop: ";
                    getline(cin, linkgrup[totalWorkshops]);
                    totalWorkshops++;
                    cout << "Workshop baru berhasil ditambahkan ! "<<endl;

                } else if (pilihan == 2) {
                    if (totalWorkshops == 0) {
                        cout << "Belum ada Workshop tersedia" << endl;
                    } else {
                        cout << "Workshop yang tersedia : \n";
                        for (int i = 0; i < totalWorkshops; i++) {
                            cout << i + 1 << ". " << workshops[i] << " - " << pemateri[i] << " - " << tanggal[i] << " - " << linkgrup[i] << "\n";
                        }
                    }
                    

                } else if (pilihan == 3) {
                    if (totalWorkshops == 0) {
                        cout << "Belum ada workshop untuk diubah." << endl;
                    } else {
                        for (int i = 0; i < totalWorkshops; i++) {
                            cout << i + 1 << ". " << workshops[i] << " - " << pemateri[i] << " - " << tanggal[i] << " - " << linkgrup[i] << "\n";
                        }
                        int i;
                        cout << "Masukkan nomor workshop yang akan diubah: ";
                        cin >> i;
                        if (i > 0 && i <= totalWorkshops) {
                            cin.ignore();
                            cout << "Masukkan nama Workshop baru: ";
                            getline(cin, workshops[i - 1]);
                            cout << "Masukkan nama pemateri baru: ";
                            getline(cin, pemateri[i - 1]);
                            cout << "Masukkan tanggal baru: ";
                            getline(cin, tanggal[i - 1]);
                            cout<< "Masukkan link grup baru: ";
                            getline(cin,linkgrup[i-1]);
                            cout << "Workshop berhasil diubah." << endl;
                        } else {
                            cout << "Nomor workshop tidak valid." << endl;
                        }
                    }

                } else if (pilihan == 4) {
                    if (totalWorkshops == 0) {
                        cout << "Belum ada workshop untuk dihapus." << endl;
                    } else {
                        for (int i = 0; i < totalWorkshops; i++) {
                            cout << i + 1 << ". " << workshops[i] << " - " << pemateri[i] << " - " << tanggal[i] << " - " << linkgrup[i] << "\n";
                        }
                        int i;
                        cout << "Masukkan nomor workshop yang akan dihapus: ";
                        cin >> i;
                        if (i > 0 && i <= totalWorkshops) {
                            for (int i = i - 1; i < totalWorkshops - 1; i++) {
                                workshops[i] = workshops[i + 1];
                                pemateri[i] = pemateri[i + 1];
                                tanggal[i] = tanggal[i + 1];
                                linkgrup[i] = linkgrup[i + 1];
                            }
                            totalWorkshops--;
                            cout << "Workshop berhasil dihapus." << endl;
                        } else {
                            cout << "Nomor workshop tidak valid." << endl;
                        }
                    }
                }else if (pilihan == 6) {
                    cout << "Program dihentikan.\n";
                    exit(0);
                }
            } while (pilihan != 5);

        } else if (username == "user" && password == "user123") {
            int pilihan;
            do {
                cout << "\n|| ===== WorkshopsToDo ===== ||\n";
                cout << "1. Lihat Workshop Tersedia\n2. Logout\n3. Keluar\nPilih: ";
                cin >> pilihan;
                cin.ignore();
                
                if (pilihan == 1) {
                    if (totalWorkshops == 0) {
                        cout << "Maaf, Tidak Ada Workshop Tersedia Untuk Saat Ini !." << endl;
                    }else {
                        for (int i = 0; i < totalWorkshops; i++) {
                            cout << i + 1 << ". " << workshops[i] << " - " << pemateri[i] << " - " << tanggal[i] << "\n";
                        }

                        int pilihanWorkshop;
                        cout << "Pilih nomor workshop untuk melihat link grup: ";
                        cin >> pilihanWorkshop;
                        cin.ignore();
                        if (pilihanWorkshop > 0 && pilihanWorkshop <= totalWorkshops) {
                            cout << "Link grup untuk " << workshops[pilihanWorkshop - 1] << " adalah: " << linkgrup[pilihanWorkshop - 1] << "\n";
                            cout<<"Silahkan join grup untuk mendapat info seputar Workshop\n";
                        } else {
                            cout << "Nomor workshop tidak valid." << endl;
                        }
                    }
                } else if (pilihan == 3) {
                    cout << "Program dihentikan.\n";
                    exit(0);
                }
            } while (pilihan != 2);
        } else {
            cout << "Login gagal!\n";
            percobaan++;
        }
    }
    return 0;
}
