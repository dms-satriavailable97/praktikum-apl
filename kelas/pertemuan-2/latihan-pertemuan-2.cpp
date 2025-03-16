#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number [3] = {1,2,4};

    //     hapus
    // for(int i = 1; i <3, i++)
    // {
    //     number[i] = number[i+1];
    // }



    // number[1] = 5;
    // number[2] = 10;

    // int totalByte = sizeof(number);
    // int singleByte = sizeof(number[0]);
    // int panjangArray = sizeof(number) / sizeof(number[0]);
    // int panjangArray2 = size(number);

    // cout <<totalByte << "\n"
    // << singleByte << "\n"
    // << panjangArray;

    // cout<< "Versi c++ saya : " << __cplusplus;

    // for (int i = 0; i < panjangArray; i++) {
    // {
    //         cout << "Nilai Array : " << number[i]<<endl;
    // }

   
    // }

    for(int i : number)
    {
        cout << "Nilai Array : " << i <<endl;

    }

    return 0;
}