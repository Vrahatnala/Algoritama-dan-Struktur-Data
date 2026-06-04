#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

bool binarySearch(int arr[], int left, int n, int target) {
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        else if (target < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minidx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minidx]) minidx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }
}

int main() {
    int n, x;
    cout << "Masukkan N dan X: ";
    cin >> n >> x;

    int arr[n];
    randomize();

    for (int i = 0; i < n; i++) {
        arr[i] = random(25) + 1;
        printf("%d ", arr[i]);
    }
    cout << endl;

    selectionSort(arr, n);

    int totalPasangan = 0;
    for (int i = 0; i < n - 1; i++) {
        int target = x - arr[i];
        if (binarySearch(arr, i + 1, n, target)) {
            totalPasangan++;
        }
    }

    cout << "Total pasangan angka yang bernilai " << x << " adalah : " << totalPasangan << endl;
    return 0;
}