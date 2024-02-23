#include "ptr.h"
#include <iostream>
ptr::ptr()
    : Cnt(0), head(nullptr), tail(nullptr)
{
}

ptr::~ptr()
{
    // 필요한 경우 추가 정리 작업을 수행할 수 있습니다.
}

void ptr::createList(string Cd, int Nd) {
    this->head = setNode(Cd, Nd);
    tail = this->head;
    indexNode();
}

int ptr::indexNode() {
    Node* Tmp = this->head;
    Cnt = 0;
    while (Tmp != nullptr) {
        Cnt++;
        Tmp = getNext(Tmp);
    }
    return Cnt;
}

void ptr::insertF(string Cd, int Nd) {
    Node* Tmp = setNode(Cd, Nd);
    setNext(Tmp, this->head);
    setPrev(this->head, Tmp);
    this->head = Tmp;
    indexNode();
}

void ptr::insertB(string Cd, int Nd) {
    Node* Tmp = setNode(Cd, Nd);
    setPrev(Tmp, this->tail);
    setNext(this->tail, Tmp);
    this->tail = Tmp;
    indexNode();
}

int ptr::deleteList() {
    Node* del = this->head;
    if (del == nullptr) {
        cout << "리스트가 없습니다." << endl;
        return 0;
    }
    while (del != nullptr) {
        Node* Tmp = getNext(del);
        delete del;
        del = Tmp;
    }
    head = nullptr;
    tail = nullptr;
    indexNode();
    return 0;
}

int ptr::displayList() {
    Node* Tmp = this->head;
    if (Tmp == nullptr) {
        cout << "리스트가 없습니다." << endl;
        return 0;
    }
    while (Tmp != nullptr) {
        cout << "Cdata : " << getCdata(Tmp) << endl;
        cout << "Ndata : " << getNdata(Tmp) << endl;
        cout << endl;
        Tmp = getNext(Tmp);
    }
    cout << "Cnt : " << this->Cnt << endl;
    return 0;
}