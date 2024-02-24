
#include "Node.h"




	Node::Node() 
		:Cdata(""), Ndata(0), Prev(nullptr), Next(nullptr)
	{

	}
	Node::~Node()
	{

	}
	string Node::getCdata(Node* Tmp) const {
		return Tmp->Cdata;
	}
	int Node::getNdata(Node* Tmp) const {
		return Tmp->Ndata;
	}
	Node* Node::getPrev(Node* Tmp) const {
		return Tmp->Prev;
	}
	Node* Node::getNext(Node* Tmp) const {
		return Tmp->Next;
	}

	void Node::setCdata(Node* Tmp, string Cd) {
		Tmp->Cdata = Cd;
	}
	void Node::setNdata(Node* Tmp, int Nd) {
		Tmp->Ndata = Nd;
	}
	void Node::setPrev(Node* Tmp, Node* Ptmp) {
		Tmp->Prev = Ptmp;
	}
	void Node::setNext(Node* Tmp, Node* Ptmp) {
		Tmp->Next = Ptmp;
	}

	Node* Node::getPrevNode(Node* Tmp) {

		return Tmp->Prev;
	}

	Node* Node::getNextNode(Node* Tmp) {

		return Tmp->Next;
	}


	Node* Node::setNode(string Cd, int Nd) {
		Node* Tmp = new Node;
		Tmp->Cdata = Cd;
		Tmp->Ndata = Nd;

		return Tmp;
	}








