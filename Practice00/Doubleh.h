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
		:Cdata(), Ndata(0), Prev(nullptr), Next(nullptr)
	{

	}
	~Node()
	{

	}

	string getCdata(Node* head) {
		
		return head->Cdata;
	}
	int getNdata(Node* head) {
		return head->Ndata;
	}

	Node* getPrev(Node* head) {
		return head->Prev;
	}
	Node* getNext(Node* head) {
		return head->Next;
	}


	Node* createNode(string Cd, int Nd) {
		Node* Tmp = new Node;
		Tmp->Cdata = Cd;
		Tmp->Ndata = Nd;

		return Tmp;
	}


	void cntSetNode(Node* head,string Cd,int Nd,int k) {
		for (int n = 1; n < k; n++) {
			head = head->Next;
		}
		head->Cdata = Cd;
		head->Ndata = Nd;

	}


	Node* insertFront(Node* &head, string Cd,int Nd) {
		Node* Tmp = new Node;
		Tmp->Cdata = Cd;
		Tmp->Ndata = Nd;


		if (head->Prev != nullptr) {
			head->Prev->Next = Tmp;
			Tmp->Prev = head->Prev;
			Tmp->Next = head;
			head->Prev = Tmp;

		}
		else {
			Tmp->Next = head;
			head->Prev = Tmp;
			head = Tmp;

		}

		return Tmp;

	}

	void insertBack(Node* &head,Node* &tail, string Cd, int Nd) {
		Node* Tmp = new Node;
		Tmp->Cdata = Cd;
		Tmp->Ndata = Nd;

		if (head->Next != nullptr) {
			head->Next->Prev = Tmp;
			Tmp->Prev = head;
			Tmp->Next = head->Next;
			head->Next = Tmp;
			
		}
		else {
			head->Next = Tmp;
			Tmp->Prev = head;
			tail = Tmp;
		}


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
	int getCnt() {
		return Cnt;
	}

	Node* getHead() {
		return head;
	}
	Node* getTail() {
		return tail;
	}


	void createList(string Cd,int Nd) {
		Node* Tmp = new Node;
		Tmp=createNode(Cd, Nd);
		head = Tmp;
		tail = Tmp;
	}

	void display() {
	
		Node* Tmp = getHead();

		if (Tmp == nullptr) {
			cout << "텅 빈 리스트입니다." << endl;
			

		}
		else {
			while (Tmp != nullptr) {
				
				cout << "Cdata : "<<getCdata(Tmp)<< endl;
				cout << "Ndata : " << getNdata(Tmp) << endl;
				cout << "Prev : " << getPrev(Tmp) << endl;
				cout << "Next : " << getNext(Tmp) << endl;

				Tmp = getNext(Tmp);
			}

		}


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