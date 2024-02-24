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


//����Ʈ�� ����
void ptr::createList(string Cd, int Nd) {
    this->head = setNode(Cd, Nd);
    tail = this->head;
    indexNode();
}


//����Ʈ�� ũ�� ����
int ptr::indexNode() {
    Node* Tmp = this->head;
    Cnt = 0;
    while (Tmp != nullptr) {
        Cnt++;
        Tmp = getNext(Tmp);
    }
    return Cnt;
}


//����Ʈ�� �տ� ��� �߰�
void ptr::insertF(string Cd, int Nd) {
    Node* Tmp = setNode(Cd, Nd);
    setNext(Tmp, this->head);
    setPrev(this->head, Tmp);
    this->head = Tmp;
    indexNode();
}

//����Ʈ�� �ڿ� ��� �߰�
void ptr::insertB(string Cd, int Nd) {
    Node* Tmp = setNode(Cd, Nd);
    setPrev(Tmp, this->tail);
    setNext(this->tail, Tmp);
    this->tail = Tmp;
    indexNode();
}

//����Ʈ�� n��°�� ��� �߰�

int ptr::insertN(string Cd, int Nd,int Num) {
    
    if (Num <= 1) {
        cout << "����Ʈ�� �� �տ� �߰��մϴ�." << endl;
        insertF(Cd, Nd);
        indexNode();
        return 1;
    }
    else if (Num > 1 && Num<this->Cnt) {
        cout << "����Ʈ�� "<< Num<<" ���� �߰��մϴ�." << endl;
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
        cout << "����Ʈ�� �� �ڿ� �߰��մϴ�." << endl;
        insertB(Cd, Nd);
        indexNode();
        return 1;
    }




}
//���ڿ� Ž��
Node* ptr::searchString(string Cd) const{
    Node* Tmp = this->head;
    while (Tmp != nullptr) {
        if (getCdata(Tmp) == Cd) {
            cout << Cd << " �� ã�ҽ��ϴ�." << endl;
            return Tmp;
        }
        
        Tmp = getNext(Tmp);

    }
    cout << Cd << " �� �� ã�ҽ��ϴ�." << endl;
    return nullptr;
}


//���� Ž��



//����Ʈ�� ����
int ptr::deleteList() {
    Node* del = this->head;
    if (del == nullptr) {
        cout << "����Ʈ�� �����ϴ�." << endl;
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

//����Ʈ�� ���
int ptr::displayList() const {
    Node* Tmp = this->head;
    if (Tmp == nullptr) {
        cout << "����Ʈ�� �����ϴ�." << endl;
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