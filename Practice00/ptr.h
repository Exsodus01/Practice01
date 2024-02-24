#pragma once
#include "Node.h"


class ptr : public Node {
private:
    int Cnt;
    Node* head;
    Node* tail;

public:
    ptr();
    ~ptr();
    void createList(std::string Cd, int Nd);
    int indexNode();
    void insertF(std::string Cd, int Nd);
    void insertB(std::string Cd, int Nd);
    int insertN(string Cd, int Nd, int Num);
    Node* searchString(string Cd) const;
 
    int deleteList();
    int displayList() const;
};