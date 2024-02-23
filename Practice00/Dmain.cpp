#include "ptr.h"





 int main(void) {
	

	 ptr list;

	 list.createList("one", 111);

	 list.insertF("two", 2);
	 list.insertF("three", 3);
	 list.insertF("four", 4);
	 list.insertF("five", 5);
	 list.insertB("six", 6);

	 list.displayList();
	
	 list.deleteList();

	 list.displayList();



	

	
	return 0;
}