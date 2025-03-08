#include <iostream>
using namespace std;
int main() {

    //LOGIN

    string nama,password;
    int percobaan=3;
    
    cout<<"========================================================"<<endl;
    cout <<"                    PROGRAM KONVERSI SUHU"<<endl;
    cout<<"========================================================"<<endl;

    while (percobaan >= 0){
        cout<<"Masukkan Nama                 :";
        getline(cin,nama);
        cout<<"Masukkan Password             :";              // Password adlaah 3 digit NIM terakhir
        cin>>password ;
        cin.ignore();
    
        cout<<"";
    
            if (nama =="Dimas Elang" && password == "027") {
                cout<<"Login berhasil sebagai "<< nama <<"!"<<endl<<endl;
                break;
            }else{
                percobaan--;
                cout<<"Password salah! Percobaan tersisa: "<< percobaan<<endl;
            }if(percobaan ==0){
                cout<<"Anda telah memasukkan password salah sebanyak 3x, program berhenti.";
                return 0;
            }
        }

    //MENU UTAMA
    int pilihan ;
    float suhu,hasil1,hasil2,hasil3 ;

    do {
        cout<<"========================================================"<<endl;
        cout <<"                    MENU KONVERSI SUHU"<<endl;
        cout<<"========================================================"<<endl;
        cout << "1. Celcius ke Fahrenheit, Reamur, Kelvin" <<endl;
        cout << "2. Fahrenheit ke Celcius, Reamur, Kelvin" <<endl;
        cout << "3. Konversi Reamur ke Celcius, Fahrenheit, Kelvin" <<endl;
        cout << "4. Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur" <<endl;
        cout << "5. Keluar" <<endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

    //KONVERSI SUHU CELCIUS

        if (pilihan == 1) {
            cout << "Masukkan suhu dalam Celcius: ";
            cin >> suhu;

            hasil1 = (suhu * 9 / 5) + 32;               // Fahrenheit
            hasil2 = suhu * 4 / 5;                      // Reamur
            hasil3 = suhu + 273.15;                     // Kelvin

            cout << "Fahrenheit : " << hasil1 <<endl;
            cout << "Reamur     : " << hasil2 <<endl;
            cout << "Kelvin     : " << hasil3 <<endl<<endl;

    //KONVERSI SUHU FAHRENHEIT

        } else if (pilihan == 2) {
            cout << "Masukkan suhu dalam Fahrenheit: ";
            cin >> suhu;

            hasil1 = (suhu - 32) * 5 / 9;                // Celcius
            hasil2 = (suhu - 32) * 4 / 9;                // Reamur
            hasil3 = (suhu - 32) * 5 / 9 + 273.15;       // Kelvin

            cout << "Celcius    : " << hasil1 <<endl;
            cout << "Reamur     : " << hasil2 <<endl;
            cout << "Kelvin     : " << hasil3 <<endl<<endl;

    //KONVERSI SUHU REAMUR

        }else if (pilihan == 3) {
            cout << "Masukkan suhu dalam Reamur: ";
            cin >> suhu;

            hasil1 = suhu * 5/4;                          // Celcius
            hasil2 = (suhu * 9/4) + 32;                   // Fahrenheit
            hasil3 = (suhu * 5/4)  + 273.15;              // Kelvin

            cout << "Celcius     : " << hasil1 <<endl;
            cout << "Fahreinheit : " << hasil2 <<endl;
            cout << "Kelvin      : " << hasil3 <<endl<<endl;

    //KONVERSI SUHU KELVIN

        } else if (pilihan == 4) {
            cout << "Masukkan suhu dalam Kelvin: ";
            cin >> suhu;

            hasil1 = suhu - 273.15;                      // Celcius
            hasil2 = (suhu - 273.15)* 9/5 + 32 ;         // Fahreinheit
            hasil3 = (suhu - 273.15) * 4 / 5;            // Reamur

            cout << "Celcius     : " << hasil1 <<endl;
            cout << "Fahreinheit : " << hasil2 <<endl;
            cout << "Reamur      : " << hasil3 <<endl<<endl;

        } else if (pilihan == 5) {
            cout << "Terimakasih."<<endl ;
        } else {
            cout << "Pilihan tidak valid!" <<endl ;
        }

    } while (pilihan != 5);
    return 0;
}