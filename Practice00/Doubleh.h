#pragma once

#include <string>
using namespace std;


class Node {
private:
	string Cdata;
	int Ndata;

	Node* Prev;
	Node* Next;


public:
	Node()
		:Cdata(""), Ndata(0), Prev(nullptr), Next(nullptr)
	{

	}
	~Node()
	{

	}
	string getCdata(Node* Tmp) {
		return Tmp->Cdata;
	}
	int getNdata(Node* Tmp) {
		return Tmp->Ndata;
	}
	Node* getPrev(Node* Tmp) {
		return Tmp->Prev;
	}
	Node* getNext(Node* Tmp) {
		return Tmp->Next;
	}

	void setCdata(Node* Tmp,string Cd) {
		Tmp->Cdata = Cd;
	}
	void setNdata(Node* Tmp, int Nd) {
		Tmp->Ndata = Nd;
	}
	void setPrev(Node* Tmp, Node* Ptmp) {
		Tmp->Prev = Ptmp;
	}
	void setNext(Node* Tmp, Node* Ptmp) {
		Tmp->Next = Ptmp;
	}

	Node* getPrevNode(Node* Tmp) {

		return Tmp->Prev;
	}
	
	Node* getNextNode(Node* Tmp) {
		
		return Tmp->Next;
	}


	Node* setNode(string Cd, int Nd) {
		Node* Tmp = new Node;
		Tmp->Cdata = Cd;
		Tmp->Ndata = Nd;

		return Tmp;
	}









};

class ptr : public Node {

private:
	int Cnt;

	Node* head;
	Node* tail;

public:
	ptr()
		:Cnt(0), head(nullptr), tail(nullptr)
	{

	}
	~ptr()
	{

	}
	
	void createList(string Cd, int Nd) {
		
		this->head = setNode(Cd, Nd);
		tail = this->head;

		indexNode();
	}

	int indexNode() {
		Node* Tmp = this->head;
		Cnt = 0;
		while (Tmp != nullptr) {
			Cnt++;
			Tmp = getNext(Tmp);
		}

		return Cnt;


	}

	void insertF(string Cd, int Nd) {

		Node* Tmp = setNode(Cd, Nd);
		setNext(Tmp, this->head);
		setPrev(this->head, Tmp);
		this->head = Tmp;

		indexNode();
	}

	void displayList() {
		Node* Tmp = this->head;

		while (Tmp != nullptr) {

			cout << "Cdata : " << getCdata(Tmp) << endl;
			cout << "Ndata : " << getNdata(Tmp) << endl;
			

			cout << endl;

			Tmp = getNext(Tmp);
		}
		cout << "Cnt : " << this->Cnt << endl;
	}

};






/*
class listDouble {
private:
	//index 관리를 위한 변수
	int Cnt;

	class Node* Head;
	class Node* Tail;

public:

	listDouble()
		:Cnt(0), Head(nullptr), Tail(nullptr)
	{
		cout << "listDouble() : " << endl;

	}
	~listDouble()
	{
		cout << "~listDouble() : " << endl;
	}

	int getCnt() {
		return Cnt;
	}

	Node* getHead() {
		return Head;
	}
	Node* getTail() {
		return Tail;
	}

	void setCnt(int Tmp) {
		Cnt = Tmp;
	}
	void setHead(Node* head) {
		Head = head;
	}
	void setTail(Node* tail) {
		Tail = tail;
	}
	void display() {
		while (!Head) {
			cout << "Cdata : " <<  << endl;

		}
	}

};

class Node : public listDouble {

private:

	string Cdata;
	int Ndata;

	Node* Prev;
	Node* Next;

public:
	Node()
		:Cdata(),Ndata(0),Prev(nullptr),Next(nullptr)
	{
		cout << "Node() : " << endl;
	}
	~Node()
	{
		cout << "~Node() : " << endl;
	}

	void createList() {
		Node* Tmp = new Node;
		setHead(Tmp);
		setTail(Tmp);

	}

	Node* createNode(Node* head) {
		Node* Tmp = new Node;

		return Tmp;
	}


	void insertFront(Node* head) {
		Node* Tmp = new Node;
		if (!head) {
		
		}

	}




};
*/

/*
class NODE {
public:
	string Cdata;
	int Ndata;

	NODE* Prev;
	NODE* Next;

	NODE()
		:Ndata(0),Prev(nullptr),Next(nullptr)
	{
		cout << "NODE() : " << endl;
	}

	~NODE()
	{



	
		cout << "~NODE() : " << endl;
	}
	int CreateList(Alpha &list,string Cd,int Nd) {

		
		NODE* Tmp = new NODE;
		Tmp->Cdata = Cd;
		Tmp->Ndata = Nd;
		Tmp->Prev = nullptr;
		Tmp->Next = nullptr;
		list.SetHead(Tmp);
		list.SetTail(Tmp);

	}

	int InserFront(NODE* &head, string Cd, int Nd) {
		
		
		NODE* Tmp = new NODE;
		Tmp->Cdata = Cd;
		Tmp->Ndata = Nd;
		if (head->Prev != nullptr) {
			head->Prev->Next = Tmp;
			Tmp->Prev = head->Prev;
			
		}
		else {
			Tmp->Prev = nullptr;
			head->Prev = Tmp;
		}
		
		Tmp->Next = head;




	}
};

class Alpha {

private:

	int Cnt;
	NODE* head;
	NODE* Tail;


public:

	Alpha()
		:Cnt(0), head(nullptr), Tail(nullptr) {

		cout << "Alpha() : " << endl;

	}
	~Alpha() {
		cout << "!Alpha() : " << endl;
	}
	int SetHead(NODE* Tmp) {
		head = Tmp;
	}
	int SetTail(NODE* Tmp) {
		Tail = Tmp;
	}
	NODE* Gethead() {

		return head;
	}
	NODE* GetTail() {

		return Tail;
	}

	
	int NodeCnt(NODE* head) {
		while (head != nullptr) {
			
			head = head->Next;
			Cnt++;
		}

		return Cnt;
	}
	NODE* Shead(NODE* head,string Cd , int Nd = 0, int Cn = 0) {
		if (Cd.empty() != true) {
			while (head != nullptr) {
				if (head->Cdata == Cd) {
					cout << "Cdata를 가진 노드 탐색 성공" << endl;
					return head;
				}
				else
					head = head->Next;
			}
			cout << "Cdata를 가진 노드 탐색 실패" << endl;
			return 0;
		}
		else if (Nd != 0) {
			while (head != nullptr) {
				if (head->Ndata == Nd) {
					cout << "Ndata를 가진 노드 탐색 성공" << endl;
					return head;
				}
				else
					head = head->Next;
			}

			cout << "Ndata를 가진 노드 탐색 실패" << endl;
			return 0;

		}
		else if (Cn != 0) {
			int c = 1;

			if (Cn > 0 && Cn < Cnt) {
				while (c < Cn) {
					head = head->Next;
					c++;
				}
				
				cout << Cn << " 번째 노드를 탐색 성공" << endl;
				return head;
			}
			else {
				cout << "List의 범위를 벗어납니다." << endl;
			}
			
		}
		else {
			cout << "검색 값이 없어서 노드 순서만 정렬합니다." << endl;
			NodeCnt(head);
			return 0;
		}
		


	}
	int Stail(NODE* Tail) {


	}
	void DisplayAll(NODE* head) {


	}


};

*/