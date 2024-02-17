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

	~NODE()
	{



	
		cout << "~NODE() : " << endl;
	}
	int CreateList(Alpha &list,string Cdata,int Ndata) {

		
		NODE* Tmp = new NODE;
		Tmp->Cdata = Cdata;
		Tmp->Ndata = Ndata;
		Tmp->Prev = nullptr;
		Tmp->Next = nullptr;
		list.SetHead(Tmp);
		list.SetTail(Tmp);

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
	int NodeSort(NODE* head) {
		while (head != nullptr) {
			
			head = head->Next;
			Cnt++;
		}

		return Cnt;
	}
	NODE* Shead(NODE* head, string Cd = "null", int Nd = 0, int Cn = 0) {
		if (Cd != "null") {
			while (head != nullptr) {
				if (head->Cdata == Cd) {
					cout << "Cdata�� ���� ��� Ž�� ����" << endl;
					return head;
				}
				else
					head = head->Next;
			}
			cout << "Cdata�� ���� ��� Ž�� ����" << endl;
			return 0;
		}
		else if (Nd != 0) {
			while (head != nullptr) {
				if (head->Ndata == Nd) {
					cout << "Ndata�� ���� ��� Ž�� ����" << endl;
					return head;
				}
				else
					head = head->Next;
			}

			cout << "Ndata�� ���� ��� Ž�� ����" << endl;
			return 0;

		}
		else if (Cn != 0) {
			int c = 1;

			if (Cn > 0 && Cn < Cnt) {
				while (c < Cn) {
					head = head->Next;
					c++;
				}
				
				cout << Cn << " ��° ��带 Ž�� ����" << endl;
				return head;
			}
			else {
				cout << "List�� ������ ����ϴ�." << endl;
			}
			
		}
		else {
			cout << "�˻� ���� ��� ��� ������ �����մϴ�." << endl;
			NodeSort(head);
			return 0;
		}
		


	}
	int Stail(NODE* Tail) {


	}
	void DisplayAll(NODE* head) {


	}


};