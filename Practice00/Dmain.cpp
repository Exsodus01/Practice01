#include "ptr.h"


 int main(void) {
	

	 ptr list;

	 list.createList("one", 111);
	 list.insertN("two", 2, 2);
	 list.insertN("three", 3, 3);
	 list.insertN("four", 4, 2);
	 
	 
	 list.displayList();
	

	 list.searchString("four");
	 list.searchString("reon");
	 list.deleteList();

	 list.displayList();



	

	
	return 0;
}