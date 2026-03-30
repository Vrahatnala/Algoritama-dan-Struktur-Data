#include<iostream>
#include<string>
using namespace std;

int main()
{
    char huruf;
    string kata;
    int angka;

    cout << "Masukkan sebuah huruf = ";
    cin >> huruf;

    cout << "Masukan sebuah kata = ";
    cin >> kata;

    cout << "Masukkan Angka= ";
    cin >> angka;

    cout << "\nHuruf yang Anda masukkan adalah " << huruf << endl;
    cout << "Kata yang Anda masukkan adalah   " << kata   << endl;
    cout << "Angka yang Anda masukkan adalah  " << angka  << endl;

    return 0;
}
