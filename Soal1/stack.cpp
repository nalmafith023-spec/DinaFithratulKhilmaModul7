#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAX;
}

bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }

    S.Top++;
    S.info[S.Top] = x;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }

    x = S.info[S.Top];
    S.Top--;
    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "TOP: ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack bantu;
    createStack(bantu);

    int x;

    while (!isEmpty(S)) {
        pop(S, x);
        push(bantu, x);
    }

    S = bantu;
}
