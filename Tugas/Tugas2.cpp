#include <conio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "=======================================" << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan head" << endl;
    cout << "2. DLLNC dengan head dan tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if (menu == 1) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Hapus Berdasarkan Target" << endl;
            cout << "7. Reset" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil) {
                case 1: tambahDepanH();    break;
                case 2: tambahBelakangH(); break;
                case 3: tampilkanH();      break;
                case 4: hapusDepanH();     break;
                case 5: hapusBelakangH();  break;
                case 6: hapusTargetH();    break;
                case 7: clearH();          break;
                default:
                    system("cls");
                    goto menu;
            }

            cout << "\nPress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 8);

    } else if (menu == 2) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "========================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Hapus Berdasarkan Target" << endl;
            cout << "7. Reset" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch (pil) {
                case 1: tambahDepanHT();    break;
                case 2: tambahBelakangHT(); break;
                case 3: tampilkanHT();      break;
                case 4: hapusDepanHT();     break;
                case 5: hapusBelakangHT();  break;
                case 6: hapusTargetHT();    break;
                case 7: clearHT();          break;
                default:
                    system("cls");
                    goto menu;
            }

            cout << "\nPress any key to continue" << endl;
            getch();
            system("cls");

        } while (pil < 8);

    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Fatih Alfayruz (2510817210011)." << endl;
    }
}

void initH() {
    head = NULL;
}

void initHT() {
    head = NULL;
    tail = NULL;
}

int isEmptyH() {
    if (head == NULL) return 1;
    else return 0;
}

int isEmptyHT() {
    if (tail == NULL) return 1;
    else return 0;
}

void tambahDepanH() {
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    getline(cin, baris);

    string arr[100];
    int jumlah = 0;
    stringstream ss(baris);
    while (ss >> arr[jumlah]) jumlah++;

    if (jumlah == 0) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }

    cout << "Data berhasil dimasukkan di bagian depan." << endl;
}

void tambahDepanHT() {
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    getline(cin, baris);

    string arr[100];
    int jumlah = 0;
    stringstream ss(baris);
    while (ss >> arr[jumlah]) jumlah++;

    if (jumlah == 0) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }

    cout << "Data berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakangH() {
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    getline(cin, baris);

    string arr[100];
    int jumlah = 0;
    stringstream ss(baris);
    while (ss >> arr[jumlah]) jumlah++;

    if (jumlah == 0) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            TNode *bantu = head;
            while (bantu->next != NULL) bantu = bantu->next;
            bantu->next = baru;
            baru->prev = bantu;
        }
    }

    cout << "Data berhasil dimasukkan di bagian belakang." << endl;
}

void tambahBelakangHT() {
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    getline(cin, baris);

    string arr[100];
    int jumlah = 0;
    stringstream ss(baris);
    while (ss >> arr[jumlah]) jumlah++;

    if (jumlah == 0) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    cout << "Data berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepanH() {
    TNode *hapus;
    string data;
    if (isEmptyH() == 0) {
        hapus = head;
        data = hapus->data;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusDepanHT() {
    TNode *hapus;
    string data;
    if (isEmptyHT() == 0) {
        hapus = head;
        data = hapus->data;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusBelakangH() {
    if (isEmptyH() == 0) {
        int total = 0;
        TNode *hitung = head;
        while (hitung != NULL) {
            total++;
            hitung = hitung->next;
        }

        int n;
        cout << "Hapus node ke-N dari belakang. Masukkan N : ";
        cin >> n;

        TNode *hapus;

        if (n <= total) {
            hapus = head;
            while (hapus->next != NULL) hapus = hapus->next;
            for (int i = 1; i < n; i++) hapus = hapus->prev;
        } else {
            int sisa = n % total;
            if (sisa == 0) {
                hapus = head;
            } else {
                hapus = head;
                for (int i = 1; i <= sisa; i++) hapus = hapus->next;
            }
        }

        string data = hapus->data;

        if (hapus->prev != NULL) hapus->prev->next = hapus->next;
        else head = hapus->next;

        if (hapus->next != NULL) hapus->next->prev = hapus->prev;

        delete hapus;
        cout << "Data \"" << data << "\" telah dihapus." << endl;

    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusBelakangHT() {
    if (isEmptyHT() == 0) {
        int total = 0;
        TNode *hitung = head;
        while (hitung != NULL) {
            total++;
            hitung = hitung->next;
        }

        int n;
        cout << "Hapus node ke-N dari belakang. Masukkan N : ";
        cin >> n;

        TNode *hapus;

        if (n <= total) {
            hapus = tail;
            for (int i = 1; i < n; i++) hapus = hapus->prev;
        } else {
            int sisa = n % total;
            if (sisa == 0) {
                hapus = head;
            } else {
                hapus = head;
                for (int i = 1; i <= sisa; i++) hapus = hapus->next;
            }
        }

        string data = hapus->data;

        if (hapus->prev != NULL) hapus->prev->next = hapus->next;
        else head = hapus->next;

        if (hapus->next != NULL) hapus->next->prev = hapus->prev;
        else tail = hapus->prev;

        delete hapus;
        cout << "Data \"" << data << "\" telah dihapus." << endl;

    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusTargetH() {
    if (isEmptyH() == 0) {
        string target;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> target;

        TNode *bantu = head;
        bool ditemukan = false;

        while (bantu != NULL) {
            TNode *berikut = bantu->next;
            if (bantu->data == target) {
                ditemukan = true;

                if (bantu->prev != NULL) bantu->prev->next = bantu->next;
                else head = bantu->next;

                if (bantu->next != NULL) bantu->next->prev = bantu->prev;

                delete bantu;
            }
            bantu = berikut;
        }

        if (ditemukan) {
            cout << "Semua data \"" << target << "\" telah berhasil dihapus." << endl;
        } else {
            cout << "Data \"" << target << "\" tidak ditemukan pada Linked List." << endl;
        }

    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusTargetHT() {
    if (isEmptyHT() == 0) {
        string target;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> target;

        TNode *bantu = head;
        bool ditemukan = false;

        while (bantu != NULL) {
            TNode *berikut = bantu->next;
            if (bantu->data == target) {
                ditemukan = true;

                if (bantu->prev != NULL) bantu->prev->next = bantu->next;
                else head = bantu->next;

                if (bantu->next != NULL) bantu->next->prev = bantu->prev;
                else tail = bantu->prev;

                delete bantu;
            }
            bantu = berikut;
        }

        if (ditemukan) {
            cout << "Semua data \"" << target << "\" telah berhasil dihapus." << endl;
        } else {
            cout << "Data \"" << target << "\" tidak ditemukan pada Linked List." << endl;
        }

    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void tampilkanH() {
    TNode *bantu = head;
    if (isEmptyH() == 0) {
        while (bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void tampilkanHT() {
    TNode *bantu = head;
    if (isEmptyHT() == 0) {
        while (bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void clearH() {
    if (isEmptyH() == 0) {
        int urutan = 1;

        while (head != NULL) {
            TNode *hapus;

            hapus = head;
            cout << "Menghapus node ke-" << urutan << " (depan) : \"" << hapus->data << "\"" << endl;
            if (head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            } else {
                initH();
            }
            delete hapus;
            urutan++;

            if (head == NULL) break;

            TNode *ekor = head;
            while (ekor->next != NULL) ekor = ekor->next;

            hapus = ekor;
            cout << "Menghapus node ke-" << urutan << " (belakang) : \"" << hapus->data << "\"" << endl;
            if (hapus->prev != NULL) {
                hapus->prev->next = NULL;
            } else {
                initH();
            }
            delete hapus;
            urutan++;
        }

        cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void clearHT() {
    if (isEmptyHT() == 0) {
        int urutan = 1;

        while (head != NULL) {
            TNode *hapus;

            hapus = head;
            cout << "Menghapus node ke-" << urutan << " (depan) : \"" << hapus->data << "\"" << endl;
            if (head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            } else {
                initHT();
            }
            delete hapus;
            urutan++;

            if (head == NULL) break;

            hapus = tail;
            cout << "Menghapus node ke-" << urutan << " (belakang) : \"" << hapus->data << "\"" << endl;
            if (tail->prev != NULL) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                initHT();
            }
            delete hapus;
            urutan++;
        }

        cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}