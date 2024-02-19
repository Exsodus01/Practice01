#include <iostream>
#include "Doubleh.h"


using namespace std;


 int main(void) {
	cout << "main() : " << endl;

	ptr listA;

	listA.createList("start",3);
	listA.insertFront(listA.getHead(), "end", 8);
	listA.display();

	

	cout << "~main() : " << endl;
	return 0;
}