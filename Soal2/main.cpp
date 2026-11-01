#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    int pilih, x;

    createStack(S);

    do {
        cout << "\n=== MENU STACK POINTER ===" << endl;
        cout << "1. Tambah Terurut" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> x;

                pushAscending(S, x);
                cout << "Data berhasil ditambahkan!" << endl;
                break;

            case 2:
                if (pop(S, x))
                    cout << "Data yang di-Pop: " << x << endl;
                else
                    cout << "Stack kosong!" << endl;
                break;

            case 3:
                printInfo(S);
                break;

            case 4:
                clearStack(S);
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilih != 4);

    return 0;
}
