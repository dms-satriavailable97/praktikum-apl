#include <iostream>
using namespace std;

struct Workshop {
    string judulworkshop,pemateri,tanggal,linkgrup;
    };

struct User{
    string username,password;
};

struct DataProgram {
    Workshop workshop[10];
    int totalWorkshops = 0;
};

int main() {
    DataProgram dataprogram;
    User user; 
    int pilihan;
    int percobaan = 3; 

    while (true) {
        cout << "\n|| ===== MENU AWAL ===== ||\n";
        cout << "1. Register\n2. Login\n3. Keluar\nPilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            cout << "\n|| ===== REGISTER ===== ||\n";
            cout << "Masukkan username baru : ";
            getline(cin, user.username);
            cout << "Masukkan Password baru : ";
            getline(cin, user.password);
        }

        else if (pilihan == 2) {
            string inputusn, inputpw;
            cout << "\n|| ===== LOGIN ===== ||\n";
            cout << "Masukkan username : ";
            getline(cin, inputusn);
            cout << "Masukkan Password : ";
            getline(cin, inputpw);

            if (inputusn == "dimas" && inputpw == "027") {
                do {
                    cout << "\n|| ===== MENU ADMIN ===== ||\n";
                    cout << "1. Tambah Workshop\n2. Lihat Workshop Tersedia\n3. Update Workshop\n4. Hapus Workshop\n5. Logout\nMasukkan Pilihan: ";
                    cin >> pilihan;
                    cin.ignore();
                    cout << "";

                    if (pilihan == 1) {
                        int i = dataprogram.totalWorkshops;
                        cout << "Masukkan nama workshop: ";
                        getline (cin, dataprogram.workshop[i].judulworkshop) ;
                        cout << "Masukkan nama pemateri: ";
                        getline (cin, dataprogram.workshop[i].pemateri) ;
                        cout << "Masukkan tanggal pelaksanaan: ";
                        getline (cin, dataprogram.workshop[i].tanggal) ;
                        cout << "Masukkan link grup workshop: ";
                        getline (cin, dataprogram.workshop[i].linkgrup) ;
                        dataprogram.totalWorkshops++;
                        cout << "Workshop baru berhasil ditambahkan ! "<<endl;

                    }else if (pilihan == 2){
                        if (dataprogram.totalWorkshops == 0) {
                            cout << "Belum ada Workshop tersedia" << endl;
                        } else {
                            cout << "Workshop yang tersedia : \n";
                            for (int i = 0; i < dataprogram.totalWorkshops; i++) {
                                cout << i + 1 << ". "
                                    << dataprogram.workshop[i].judulworkshop << " - "
                                    << dataprogram.workshop[i].pemateri << " - "
                                    << dataprogram.workshop[i].tanggal << " - "
                                    << dataprogram.workshop[i].linkgrup
                                    << "\n";
                            }
                        }
                            
                    }else if (pilihan == 3){
                        if (dataprogram.totalWorkshops == 0) {
                            cout << "Belum ada workshop untuk diubah." << endl;
                        } else {
                            for (int i = 0; i < dataprogram.totalWorkshops; i++) {
                                cout << i + 1 << ". "
                                    << dataprogram.workshop[i].judulworkshop << " - "
                                    << dataprogram.workshop[i].pemateri << " - "
                                    << dataprogram.workshop[i].tanggal << " - "
                                    << dataprogram.workshop[i].linkgrup
                                    << "\n";
                            }
                            int pilih;
                            cout << "Masukkan nomor workshop yang akan diubah: ";
                            cin >> pilih;
                            if (pilih > 0 && pilih <= dataprogram.totalWorkshops) {
                                cin.ignore();
                                cout << "Masukkan nama Workshop baru: ";
                                getline(cin, dataprogram.workshop[pilih - 1].judulworkshop);
                                cout << "Masukkan nama pemateri baru: ";
                                getline(cin, dataprogram.workshop[pilih - 1].pemateri);
                                cout << "Masukkan tanggal baru: ";
                                getline(cin, dataprogram.workshop[pilih - 1].tanggal);
                                cout<< "Masukkan link grup baru: ";
                                getline(cin,dataprogram.workshop[pilih-1].linkgrup);
                                cout << "Workshop berhasil diubah." << endl;
                            } else {
                                cout << "Nomor workshop tidak valid." << endl;
                            }
                        }
                    
                    }else if (pilihan == 4){
                        if (dataprogram.totalWorkshops == 0) {
                            cout << "Belum ada workshop untuk dihapus." << endl;
                        } else {
                            for (int i = 0; i < dataprogram.totalWorkshops; i++) {
                                cout << i + 1 << ". "
                                    << dataprogram.workshop[i].judulworkshop << " - "
                                    << dataprogram.workshop[i].pemateri << " - "
                                    << dataprogram.workshop[i].tanggal << " - "
                                    << dataprogram.workshop[i].linkgrup
                                    << "\n";
                            }

                            int input ;
                            cout << "Masukkan nomor workshop yang akan dihapus: ";
                            cin >> input;
                            if (input >= 1 && input <= dataprogram.totalWorkshops) {
                                for (int i = input - 1; i < dataprogram.totalWorkshops - 1; i++) {
                                    dataprogram.workshop[i].judulworkshop = dataprogram.workshop[i + 1].judulworkshop;
                                    dataprogram.workshop[i].pemateri = dataprogram.workshop[i + 1].pemateri;
                                    dataprogram.workshop[i].tanggal = dataprogram.workshop[i + 1].tanggal;
                                    dataprogram.workshop[i].linkgrup = dataprogram.workshop[i + 1].linkgrup;
                                }
                                dataprogram.totalWorkshops--;
                                cout << "Workshop berhasil dihapus." << endl;
                            } else {
                                cout << "Nomor workshop tidak valid." << endl;
                            }
                        }
                    }
                
                } while (pilihan != 5);

            }else if (inputusn == user.username && inputpw == user.password) {
                cout << "\n|| ===== MENU PENDAFTAR ===== ||\n";
                do {
                    cout << "\n|| ===== WorkshopsToDo ===== ||\n";
                    cout << "1. Lihat Workshop Tersedia\n2. Logout\nPilih: ";
                    cin >> pilihan;
                    cin.ignore();
                    
                    if (pilihan == 1) {
                        if (dataprogram.totalWorkshops == 0) {
                            cout << "Maaf, belum ada workshop yang tersedia untuk sekarang." << endl;
                        } else {
                            for (int i = 0; i < dataprogram.totalWorkshops; i++) {
                                cout << i + 1 << ". "
                                    << dataprogram.workshop[i].judulworkshop << " - "
                                    << dataprogram.workshop[i].pemateri << " - "
                                    << dataprogram.workshop[i].tanggal << " - "
                                    << dataprogram.workshop[i].linkgrup
                                    << "\n";
                            }
    
                            int pilihanWorkshop;
                            cout << "Pilih nomor workshop untuk melihat link grup: ";
                            cin >> pilihanWorkshop;
                            cin.ignore();
                            if (pilihanWorkshop > 0 && pilihanWorkshop <= dataprogram.totalWorkshops) {
                                cout << "Link grup untuk " << dataprogram.workshop[pilihanWorkshop - 1].judulworkshop 
                                << " adalah: " << dataprogram.workshop[pilihanWorkshop - 1].linkgrup << "\n";
                                cout<<"Silahkan join grup untuk mendapat info seputar Workshop\n";
                            } else {
                                cout << "Nomor workshop tidak valid." << endl;
                            }
                        }
                    }

                } while (pilihan != 2);


            }else {
                percobaan--;
                cout << "Login gagal! Sisa percobaan: " << percobaan << endl;
                if (percobaan == 0) {
                    cout << "Anda telah gagal login 3 kali. Program dihentikan.\n";
                    exit(0);
                }
            }
        }

        else if (pilihan == 3) {
            cout << "Program dihentikan.\n";
            exit(0);
        }

        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}

