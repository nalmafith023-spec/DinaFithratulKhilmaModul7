#include <iostream>
#include <new>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

Node* alokasi(int x) {
    Node *P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(Node *P) {
    delete P;
}

bool push(Stack &S, int x) {
    Node *P = alokasi(x);

    if (P == nullptr) {
        return false;
    }

    P->next = S.Top;
    S.Top = P;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }

    Node *P = S.Top;
    x = P->info;
    S.Top = P->next;
    dealokasi(P);

    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "TOP: ";
    Node *P = S.Top;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);

    int temp;

    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, temp);
        push(bantu, temp);
    }

    push(S, x);

    while (!isEmpty(bantu)) {
        pop(bantu, temp);
        push(S, temp);
    }
}

void clearStack(Stack &S) {
    int x;

    while (!isEmpty(S)) {
        pop(S, x);
    }

    S.Top = nullptr;
}
