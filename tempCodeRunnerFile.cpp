#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number [5] = {1,2,3,4};

    int totalNyte = sizeof(number);
    int singleByte = size(number[0]);
    int panjangArray = sizeof(number) / sizeof(number[0]);

    cout <<totalByte << "\n"
    << singleByte << "\n"
    << panjangArray;

    return 0;
}