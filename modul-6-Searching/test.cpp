#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <conio.h>

using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequentialSearching() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;

    randomize();

    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d\n", save);
    } else {
        printf("Data tidak ada!\n");
    }
}

void binarySearching() {
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data? ";
    cin >> n;
    int angka[n];

    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    // Bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n--------------------------------------------------------------------------------\n";

    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true) {
        cout << "Angka ditemukan! ";
    } else {
        cout << "Angka tidak ditemukan!";
    }
}

void jelaskanPerbedaan() {
    cout << "================================================================" << endl;
    cout << "PERBEDAAN SEQUENTIAL SEARCHING DAN BINARY SEARCHING" << endl;
    cout << "================================================================" << endl;
    cout << endl;
    cout << "Sequential searching dan binary searching adalah dua algoritma" << endl;
    cout << "yang digunakan untuk mencari data. Keduanya memiliki cara kerja" << endl;
    cout << "yang berbeda dan cocok digunakan dalam situasi yang berbeda pula." << endl;
    cout << endl;
    cout << "1. SEQUENTIAL SEARCHING" << endl;
    cout << "   Sequential searching bekerja dengan cara memeriksa data satu" << endl;
    cout << "   per satu mulai dari elemen pertama hingga elemen terakhir." << endl;
    cout << "   Jika data yang dicari ditemukan, proses berhenti. Jika sudah" << endl;
    cout << "   sampai akhir dan tidak ditemukan, maka data dinyatakan tidak ada." << endl;
    cout << "   Kelebihan :" << endl;
    cout << "   - Mudah dipahami dan sederhana." << endl;
    cout << "   - Tidak memerlukan data yang terurut." << endl;
    cout << "   - Cocok untuk data yang jumlahnya sedikit." << endl;
    cout << "   Kekurangan :" << endl;
    cout << "   - Kurang efisien untuk data yang besar." << endl;
    cout << "   - Semakin banyak data, semakin lama waktu pencariannya." << endl;
    cout << endl;
    cout << "2. BINARY SEARCHING" << endl;
    cout << "   Binary searching bekerja dengan cara membagi data menjadi dua" << endl;
    cout << "   bagian, lalu membandingkan data di tengah dengan data yang dicari." << endl;
    cout << "   Jika data yang dicari lebih kecil, pencarian dilanjutkan ke bagian" << endl;
    cout << "   kiri. Jika lebih besar, ke bagian kanan. Proses ini terus berulang" << endl;
    cout << "   hingga data ditemukan atau tidak ada lagi yang bisa dibagi." << endl;
    cout << "   Kelebihan :" << endl;
    cout << "   - Jauh lebih cepat dibanding sequential untuk data besar." << endl;
    cout << "   - Efisien karena setiap langkah mengurangi setengah data." << endl;
    cout << "   Kekurangan :" << endl;
    cout << "   - Data harus diurutkan terlebih dahulu sebelum dicari." << endl;
    cout << "   - Lebih rumit untuk dipahami dibanding sequential searching." << endl;
    cout << "================================================================" << endl;
}

int main() {
    int pilih;

    do {
        system("cls");
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        system("cls");

        switch (pilih) {
            case 1:
                sequentialSearching();
                break;
            case 2:
                binarySearching();
                break;
            case 3:
                jelaskanPerbedaan();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                cout << "Program was made by Fatih Alfayruz (2510817210011)." << endl;
        }

        if (pilih != 4) {
            cout << "\nPress Enter to continue!" << endl;
            cin.ignore(); cin.get();
        }

    } while (pilih != 4);
}