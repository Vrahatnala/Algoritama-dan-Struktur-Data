#include <iostream>
#include <conio.h> 
using namespace std; 
#define max 5 
struct stack {
    int atas = -1;
    int data[max];
};
stack Tumpuk;
int penuh() {
    if(Tumpuk.atas == max-1)
        return 1;
    else
        return 0;
}
int kosong() { 
    if(Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}
void input(int data) {
    if (penuh()==1) {
        cout << "Tumpukan Penuh" << endl;
    } else {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack" << endl;
    }
}
void hapus() {
    if (kosong()==0) {
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Teratas Sudah Terambil" << endl;
        Tumpuk.atas--;
    } else
        cout << " Data Kosong" << endl;
}
void tampil() {
    if (kosong()==0) {
        for(int i=Tumpuk.atas;i>=0;i--) {
            cout << "Tumpukan Ke " << i+1 << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong" << endl;
    }
}
void bersih() {
    Tumpuk.atas=-1;
    cout << "Tumpukan Kosong!" << endl;
}
int main() {
    int pilihan;
    do {
        cout << "STACK" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. CLEAR" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN :";
        cin >> pilihan;
       
        switch (pilihan) {
        case 1:
            int a;
            cout << "Masukkan Data: "; cin >> a;
            input(a);
            break;
        case 2:
            hapus();
            break;
        case 3:
            tampil();
            break;
        case 4:
            bersih();
            break;
        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "Press any key to continue" << endl;
        getch();
        system("cls");
    } while (pilihan < 5);
    
}