#include "Food.h"

class Menu {
public:
	list<Food> kitMenu;
	void addFood(string name, int price) {
		Food f = Food(name, price);
		kitMenu.push_front(f);
	}
	void removeFood(string name) {
		Food f = Food(name, 0);
		kitMenu.remove(f);
	}
	void printMenu() {
		cout << "============Menu=============" << endl;
		int i = 1;
		for (list<Food>::iterator it = kitMenu.begin(); it != kitMenu.end(); it++, i++) {
			Food f = *it;
			cout << i << ": " << f.name << ' ' << f.price << endl;
		}
		cout << "=============================" << endl;
	}

	void initDummy() {
		addFood("chicken", 5);
		addFood("pasta", 8);
		addFood("burger", 7);
		addFood("pizza", 10);
		addFood("steak", 20);
	}
};