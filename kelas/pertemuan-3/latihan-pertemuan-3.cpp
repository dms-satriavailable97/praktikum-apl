#include <iostream>
using namespace std;


struct tanggal{
    int hari;
    int bulan;
    int tahun;
};


struct Mahasiswa{
    string nama ;
    int nim;
    string gender;
    tanggal tanggallahir;
};

// typedef struct {
//     string nama ;
//     int nim;
//     string gender;
// }Mahasiswa;

int main() {
    Mahasiswa mhsbaru;
    Mahasiswa mhslama;

    mhsbaru.nama = "Rangga";
    mhsbaru.nim = 043;
    mhsbaru.gender = "lakik";
    mhsbaru.tanggallahir.hari = 3;
    mhsbaru.tanggallahir.bulan = 3;
    mhsbaru.tanggallahir.tahun = 2006;

    cout<<mhsbaru.nama <<endl;
    cout<<mhsbaru.nim <<endl;
    cout<<mhsbaru.gender <<endl;

    cout << mhslama.nama << endl;
    cout << "Tanggal lahir : " << mhsbaru.tanggallahir.hari <<"/"<< mhsbaru.tanggallahir.bulan << "/" << mhsbaru.tanggallahir.tahun << endl;

    Mahasiswa mhsAbadi [6];
    mhsAbadi[0].nama = "DImas";
    mhsAbadi[1].nama = "Tiko";
    mhsAbadi[2].nama = "Ripan";
    mhsAbadi[3].nama = "Nopal";
    mhsAbadi[4].nama = "Nahya";
    mhsAbadi[5].nama = "Sapar";

    for (int i = 0; i < size(mhsAbadi); i++){
        cout << mhsAbadi[i].nama << endl;
    }

    return 0;
}