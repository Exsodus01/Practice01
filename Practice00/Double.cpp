#include <iostream>
#include "Doubleh.h"


using namespace std;


 int main(void) {
	

	 ptr list;

	 list.createList("one", 44);

	 list.insertF("two", 23);
	 list.insertF("three", 23);
	 list.insertF("four", 23);
	 list.insertF("five", 23);


	 list.displayList();
	



	

	
	return 0;
}