#include <iostream>
using namespace std;

//MERGE SORT (rekursifny) 
void merge(char data[], int kiri, int tengah, int kanan) {
    int ukuranKiri = tengah - kiri + 1;
    int ukuranKanan = kanan - tengah;

    char bagianKiri[100], bagianKanan[100];
    for (int i = 0; i < ukuranKiri; i++) bagianKiri[i] = data[kiri + i];
    for (int j = 0; j < ukuranKanan; j++) bagianKanan[j] = data[tengah + 1 + j];

    int i = 0, j = 0, posisi = kiri;
    while (i < ukuranKiri && j < ukuranKanan) {
        if (bagianKiri[i] <= bagianKanan[j]) data[posisi++] = bagianKiri[i++];
        else data[posisi++] = bagianKanan[j++];
    }
    while (i < ukuranKiri) data[posisi++] = bagianKiri[i++];
    while (j < ukuranKanan) data[posisi++] = bagianKanan[j++];
}

void mergeSort(char data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSort(data, kiri, tengah);       //kiri
        mergeSort(data, tengah + 1, kanan);  //kanane
        merge(data, kiri, tengah, kanan);
    }
}

//QUICK SORT (rekursif)
int cariPivot(char data[], int awal, int akhir) {
    char pivot = data[akhir];
    int posisiPivot = awal - 1;
    for (int j = awal; j < akhir; j++) {
        if (data[j] <= pivot) {
            posisiPivot++;
            char sementara = data[posisiPivot];
            data[posisiPivot] = data[j];
            data[j] = sementara;
        }
    }
    char sementara = data[posisiPivot + 1];
    data[posisiPivot + 1] = data[akhir];
    data[akhir] = sementara;
    return posisiPivot + 1;
}

void quickSort(char data[], int awal, int akhir) {
    if (awal < akhir) {
        int posisiPivot = cariPivot(data, awal, akhir);
        quickSort(data, awal, posisiPivot - 1);  // kirire
        quickSort(data, posisiPivot + 1, akhir); // kanane
    }
}

int main() {
    char dataAsli[100];
    char dataTemp[100];
    int panjang, pilihan;

    cout << "Masukkan data (Nama/NIM): ";
    cin.getline(dataAsli, 100);

    panjang = 0;
    while (dataAsli[panjang] != '\0') panjang++;

    cout << "Data awal: " << dataAsli << endl;

    do {
        for (int i = 0; i <= panjang; i++) dataTemp[i] = dataAsli[i];

        cout << "\n==== SORTING ====" << endl;
        cout << "1. Insertion Sort (Nama)" << endl;
        cout << "2. Merge Sort (Nama)" << endl;
        cout << "3. Shell Sort (Nama)" << endl;
        cout << "4. Quick Sort (NIM)" << endl;
        cout << "5. Bubble Sort (NIM)" << endl;
        cout << "6. Selection Sort (NIM)" << endl;
        cout << "7. Exit" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            // Insertion Sort
            for (int i = 1; i < panjang; i++) {
                char karakter = dataTemp[i];
                int j = i - 1;
                while (j >= 0 && dataTemp[j] > karakter) {
                    dataTemp[j+1] = dataTemp[j];
                    j--;
                }
                dataTemp[j+1] = karakter;
            }
            cout << "Hasil Insertion Sort: " << dataTemp << endl;

        } else if (pilihan == 2) {
            // Merge Sort 
            mergeSort(dataTemp, 0, panjang - 1);
            cout << "Hasil Merge Sort: " << dataTemp << endl;

        } else if (pilihan == 3) {
            // Shell Sort
            int jarak = panjang / 2;
            while (jarak > 0) {
                for (int i = jarak; i < panjang; i++) {
                    char karakter = dataTemp[i];
                    int j = i;
                    while (j >= jarak && dataTemp[j - jarak] > karakter) {
                        dataTemp[j] = dataTemp[j - jarak];
                        j -= jarak;
                    }
                    dataTemp[j] = karakter;
                }
                jarak /= 2;
            }
            cout << "Hasil Shell Sort: " << dataTemp << endl;

        } else if (pilihan == 4) {
            // Quick Sort 
            quickSort(dataTemp, 0, panjang - 1);
            cout << "Hasil Quick Sort: " << dataTemp << endl;

        } else if (pilihan == 5) {
            // Bubble Sort
            for (int i = 0; i < panjang - 1; i++) {
                for (int j = 0; j < panjang - i - 1; j++) {
                    if (dataTemp[j] > dataTemp[j+1]) {
                        char sementara = dataTemp[j];
                        dataTemp[j] = dataTemp[j+1];
                        dataTemp[j+1] = sementara;
                    }
                }
            }
            cout << "Hasil Bubble Sort: " << dataTemp << endl;

        } else if (pilihan == 6) {
            // Selection Sort
            for (int i = 0; i < panjang - 1; i++) {
                int indeksMin = i;
                for (int j = i + 1; j < panjang; j++) {
                    if (dataTemp[j] < dataTemp[indeksMin]) indeksMin = j;
                }
                char sementara = dataTemp[i];
                dataTemp[i] = dataTemp[indeksMin];
                dataTemp[indeksMin] = sementara;
            }
            cout << "Hasil Selection Sort: " << dataTemp << endl;

        } else if (pilihan == 7) {
            cout << "Program selesai." << endl;
            cout << "Program made by: Fatih Alfayruz NIM: 2510817210011." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 7);

    return 0;
}