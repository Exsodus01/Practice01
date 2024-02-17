#pragma once
#include <string>
using namespace std;
class NODE {
public:
	string Cdata;
	int Ndata;

	NODE* Prev;
	NODE* Next;

	NODE()
		:Cdata("null"),Ndata(0),Prev(nullptr),Next(nullptr)
	{
		cout << "NODE() : " << endl;
	}
	NODE(string a, int b)
		:Cdata(a), Ndata(b),Prev(nullptr),Next(nullptr) 
	{
		cout << "NODE(string,int) : " << endl;
	}

	~NODE()
	{



	
		cout << "~NODE() : " << endl;
	}
	int CreateList(NODE* head,string Cdata,int Ndata) {

		
		NODE* Tmp = new NODE;
		Tmp->Cdata = Cdata;
		Tmp->Ndata = Ndata;
		Tmp->Prev = nullptr;
		Tmp->Next = nullptr;
		Aptr.SetHead(Tmp);
		Aptr.SetTail(Tmp);


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
	int SetHead(NODE* Tmp) {
		head = Tmp;
	}
	int SetTail(NODE* Tmp) {
		Tail = Tmp;
	}
	int Shead(NODE* head) {
		if (head == nullptr) {

			cout << "List is null" << endl;


		}
		else {

			while()


		}

	}
	int Stail(NODE* Tail) {


	}
	void DisplayAll(NODE* head) {


	}


};