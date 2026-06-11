#include <iostream>
using namespace std;

typedef struct TNode {
    int data;
    TNode *left;
    TNode *right;
};

TNode *root = NULL;

TNode* insert(TNode *node, int data) {
    if (node == NULL) {
        TNode *baru = new TNode;
        baru->data = data;
        baru->left = NULL;
        baru->right = NULL;
        return baru;
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

int hitungTinggi(TNode *node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return 0;

    int tinggiKiri = 0;
    if (node->left != NULL) {
        tinggiKiri = 1 + hitungTinggi(node->left);
    }

    int tinggiKanan = 0;
    if (node->right != NULL) {
        tinggiKanan = 1 + hitungTinggi(node->right);
    }

    if (tinggiKiri > tinggiKanan) return tinggiKiri;
    else return tinggiKanan;
}

int cariJarakTerjauh(TNode *node) {
    if (node == NULL) return 0;

    int tinggiKiri = 0;
    if (node->left != NULL) {
        tinggiKiri = 1 + hitungTinggi(node->left);
    }

    int tinggiKanan = 0;
    if (node->right != NULL) {
        tinggiKanan = 1 + hitungTinggi(node->right);
    }

    int jarakMelaluiNodeSekarang = tinggiKiri + tinggiKanan;
    int jarakMaksKiri = cariJarakTerjauh(node->left);
    int jarakMaksKanan = cariJarakTerjauh(node->right);

    int nilaiMaksimal = jarakMelaluiNodeSekarang;
    if (jarakMaksKiri > nilaiMaksimal) nilaiMaksimal = jarakMaksKiri;
    if (jarakMaksKanan > nilaiMaksimal) nilaiMaksimal = jarakMaksKanan;

    return nilaiMaksimal;
}

int main() {
    int n, data;
    printf("Masukkan panjang data : ");
    cin >> n;

    printf("Masukkan data sebanyak %d  : ", n);
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    int hasil = cariJarakTerjauh(root);
    cout << "Hasil Perhitungan jarak terjauh adalah : " << hasil << endl;
    return 0;
}