#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    int pilih, x;

    createStack(S);

    do {
        cout << "\n=== MENU STACK ===" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> x;

                if (push(S, x))
                    cout << "Data berhasil ditambahkan!" << endl;
                else
                    cout << "Stack penuh!" << endl;
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
                balikStack(S);
                cout << "Stack berhasil dibalik!" << endl;
                break;

            case 5:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilih != 5);

    return 0;
}