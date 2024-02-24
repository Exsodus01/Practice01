#include "ptr.h"
#include <iostream>
ptr::ptr()
    : Cnt(0), head(nullptr), tail(nullptr)
{

}

ptr::~ptr()
{
    if (this->head != nullptr) {
        deleteList();
    }

}


//리스트의 생성
void ptr::createList(string Cd, int Nd) {
    this->head = setNode(Cd, Nd);
    tail = this->head;
    indexNode();
}


//리스트의 크기 측정
int ptr::indexNode() {
    Node* Tmp = this->head;
    Cnt = 0;
    while (Tmp != nullptr) {
        Cnt++;
        Tmp = getNext(Tmp);
    }
    return Cnt;
}


//리스트의 앞에 노드 추가
void ptr::insertF(string Cd, int Nd) {
    Node* Tmp = setNode(Cd, Nd);
    setNext(Tmp, this->head);
    setPrev(this->head, Tmp);
    this->head = Tmp;
    indexNode();
}

//리스트의 뒤에 노드 추가
void ptr::insertB(string Cd, int Nd) {
    Node* Tmp = setNode(Cd, Nd);
    setPrev(Tmp, this->tail);
    setNext(this->tail, Tmp);
    this->tail = Tmp;
    indexNode();
}

//리스트의 n번째에 노드 추가

int ptr::insertN(string Cd, int Nd,int Num) {
    
    if (Num <= 1) {
        cout << "리스트의 맨 앞에 추가합니다." << endl;
        insertF(Cd, Nd);
        indexNode();
        return 1;
    }
    else if (Num > 1 && Num<this->Cnt) {
        cout << "리스트의 "<< Num<<" 번에 추가합니다." << endl;
        int k = 1;
        Node* a = this->head;
        Node* Tmp = setNode(Cd, Nd);
        while (k < Num) {
            a = this->getNext(a);
            k++;
        }
        this->setPrev(Tmp, this->getPrev(a));
        this->setNext(Tmp, a);
        this->setNext(this->getPrev(a),Tmp);
        indexNode();

        return 0;
    }
    else {
        cout << "리스트의 맨 뒤에 추가합니다." << endl;
        insertB(Cd, Nd);
        indexNode();
        return 1;
    }




}
//문자열 탐색
Node* ptr::searchString(string Cd) const{
    Node* Tmp = this->head;
    while (Tmp != nullptr) {
        if (getCdata(Tmp) == Cd) {
            cout << Cd << " 를 찾았습니다." << endl;
            return Tmp;
        }
        
        Tmp = getNext(Tmp);

    }
    cout << Cd << " 를 못 찾았습니다." << endl;
    return nullptr;
}


//숫자 탐색



//리스트의 삭제
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

//리스트의 출력
int ptr::displayList() const {
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