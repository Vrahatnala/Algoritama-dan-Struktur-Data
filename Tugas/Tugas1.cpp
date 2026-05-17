#include <conio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

typedef struct TNode{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main(){
    init();
    do{
    cout << "Single Linked List Circular (SLLC)" << endl;
    cout << "==================================" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah belakang" << endl;
    cout << "3. Hapus Depan" << endl;
    cout << "4. Hapus Belakang" << endl;
    cout << "5. Tampilkan Data" << endl;
    cout << "6. Hapus Semua Elemen" << endl;
    cout << "7. Cari Data" << endl;
    cout << "8. Hapus Setiap Data Tertentu" << endl;
    cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
    cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
    cout << "11. Quit" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    pil = atoi(pilihan);

    switch(pil){
    case 1:
        tambahDepan();
        break;
    case 2:
        tambahBelakang();
        break;
    case 3:
        hapusDepan();
        break;
    case 4:
        hapusBelakang();
        break;
    case 5:
        tampilkan();
        break;
    case 6:
        reset();
        break;
    case 7:
        cariData();
        break;
    case 8:
        hapusData();
        break;
    case 9:
        sisipkanSebelum();
        break;
    case 10:
        sisipkanSetelah();
        break;
    default:
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Fatih Alfayruz (2510817210011)." << endl;
    }

    cout << "\nPress Enter to continue!" << endl;
    cin.ignore(); cin.get();
    system("cls");

    } while (pil < 11);
}

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if (head == NULL) return 1;
    else return 0;
}

void tambahDepan(){
    string baris;
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    getline(cin, baris);

    string arr[100];
    int jumlah = 0;
    stringstream ss(baris);
    while (ss >> arr[jumlah]) {
        jumlah++;
    }

    if (jumlah == 0){
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    for (int i = jumlah - 1; i >= 0; i--){
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = baru;

        if (isEmpty()){
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }

    cout << "Data berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakang(){
    cout << "Masukkan data : ";
    TNode *baru;
        baru = new TNode;
        cin >> dataBaru;
        baru->data = dataBaru;
        baru->next = baru;

    if(isEmpty() == 1){
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepan(){
    if (isEmpty() == 0){
        int total = 0;
        TNode *hitung = head;
        do {
            total++;
            hitung = hitung->next;
        } while (hitung != head);

        int n;
        cout << "Hapus node ke-N dari depan. Masukkan N : ";
        cin >> n;

        if (n > total){
            cout << "N melebihi jumlah node, node yang dihapus adalah tail." << endl;
            n = total;
        }

        TNode *hapus = head;
        TNode *sebelum = NULL;

        for (int i = 1; i < n; i++){
            sebelum = hapus;
            hapus = hapus->next;
        }

        dataHapus = hapus->data;

        if (hapus == head && hapus == tail){
            init();
        } else if (hapus == head){
            head = head->next;
            tail->next = head;
        } else if (hapus == tail){
            tail = sebelum;
            tail->next = head;
        } else {
            sebelum->next = hapus->next;
        }

        delete hapus;
        cout << "Data \"" << dataHapus << "\" pada posisi ke-" << n << " dari depan telah dihapus." << endl;

    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusBelakang(){
    if (isEmpty() == 0){
        int total = 0;
        TNode *hitung = head;
        do {
            total++;
            hitung = hitung->next;
        } while (hitung != head);

        int n;
        cout << "Hapus node ke-N dari belakang. Masukkan N : ";
        cin >> n;

        if (n > total){
            cout << "N melebihi jumlah node, node yang dihapus adalah head." << endl;
            n = total;
        }

        int posDepan = total - n + 1;

        TNode *hapus = head;
        TNode *sebelum = NULL;

        for (int i = 1; i < posDepan; i++){
            sebelum = hapus;
            hapus = hapus->next;
        }

        dataHapus = hapus->data;

        if (hapus == head && hapus == tail){
            init();
        } else if (hapus == head){
            head = head->next;
            tail->next = head;
        } else if (hapus == tail){
            tail = sebelum;
            tail->next = head;
        } else {
            sebelum->next = hapus->next;
        }

        delete hapus;
        cout << "Data \"" << dataHapus << "\" pada posisi ke-" << n << " dari belakang telah dihapus." << endl;

    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void tampilkan(){
    if (isEmpty() == 0) {
        TNode *bantu;
        bantu = head;
    do {
        cout << bantu->data << " ";
        bantu = bantu->next;
    } while (bantu != head);
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void reset(){
    if (isEmpty() == 0){
        int urutan = 1;

        while (isEmpty() == 0){
            TNode *hapus = head;
            cout << "Menghapus node ke-" << urutan << " : \"" << hapus->data << "\"" << endl;

            if (head == tail){
                init();
            } else {
                head = head->next;
                tail->next = head;
            }

            delete hapus;
            urutan++;
        }

        cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void cariData(){
    if(isEmpty() == 0){
        string cari;
        cout << "Masukkan data yang ingin dicari : ";
        cin >> cari;

        TNode *bantu, *bantuTampilkan;
        bool apaDitemukan = false;

        bantu = head;

    do {
        if(cari == bantu->data){
            cout << "Setiap data yang berada di dalam tanda kurung siku ([...])"
            << "merupakan data yang anda cari." << endl;
            cout << "Linked List : ";
            bantuTampilkan = head;

    do {
        if(cari == bantuTampilkan->data)
            cout << "[" << bantuTampilkan->data << "] ";
        else
            cout << bantuTampilkan->data << ' ';
            bantuTampilkan = bantuTampilkan->next;
        } while (bantuTampilkan != head);

        apaDitemukan = true;
        cout << endl;
        break;
    }
        bantu = bantu->next;
    }   while (bantu != head);

    if (apaDitemukan == false)
    cout <<"Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
        } else cout << "Tidak terdapat pada Linked List." << endl;
}

void hapusData() {
    if(isEmpty() == 0){
    string cari;
    cout << "Masukkan data yang ingin dihapus : ";
    cin >> cari;

    TNode *bantu, *sebelum, *hapus[255], *bantu2;
    int hitung = 0;
    bool apaDitemukan = false;

    bantu = head;

    do {
    bantu2 = bantu;
    if(cari == bantu->data){
        hapus[hitung++] = bantu;
        apaDitemukan = true;
        if (bantu != head && bantu != tail){
        sebelum->next = bantu->next;
        bantu2 = sebelum;
        }
    }
    sebelum = bantu2;
    bantu = bantu->next;
    } while(bantu != head);

    if (apaDitemukan == true) {
        for(int i = 0; i < hitung; i++){
        if (hapus[i] == head){
            hapusDepan();
        } else if (hapus[i] == tail){
            hapusBelakang();
        } else {
            delete hapus[i];
        }
    }

    cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List telah dihapus";
    } else cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;

} else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSebelum()
{
    if(isEmpty() == 0){
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda = false;

        bantu = head;
        sebelum = tail;

        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

    do {
        if(nextData == bantu->data){
            apaAda = true;
            break;
    } else {
        sebelum = bantu;
        bantu = bantu->next;
    }
    } while ( bantu != head );

    if (apaAda == true){
        cout << "Masukkan data yang ingin ditambahkan : ";
        cin >> dataBaru;

        TNode *baru;
        baru = new TNode;

        baru->data = dataBaru;
        baru->next = bantu;

        sebelum->next = baru;

        if (bantu == head){
        head = baru;
    }

        cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \"" << nextData << "\"." << endl;
    } else {
        cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
    }
} else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSetelah(){
    if(isEmpty() == 0){
        TNode *bantu;
        string prevData;
        bool apaAda = false;

        bantu = head;

        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

    do {
        if(prevData == bantu->data){
            apaAda = true;
            break;
    } else {
        bantu = bantu->next;
    }
    } while (bantu != head);

    if (apaAda == true){
        cout << "Masukkan data yang ingin ditambahkan : ";
        cin >> dataBaru;

        TNode *baru;
        baru = new TNode;

        baru->data = dataBaru;
        baru->next = bantu->next;

        bantu->next = baru;

        if (bantu == tail){
        tail = baru;
    }

    cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \"" << prevData << "\"." << endl;
    } else {
    cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
    }
} else cout << "Tidak terdapat data pada Linked List." << endl;
}