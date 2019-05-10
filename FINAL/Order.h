#include "Menu.h"

class Order {
public:
	list<Food> items;
	int totalPrice, roomNum;
	string status;

	Order() {

	}

	Order(list<int> foodNums, list<Food> kitMenu, int roomNumber) {
		totalPrice = 0;
		roomNum = roomNumber;
		status = "ordered";
		for (list<int>::iterator it = foodNums.begin(); it != foodNums.end(); it++) {
			list<Food>::iterator it2 = kitMenu.begin();
			advance(it2, *it - 1);
			Food f = *it2;
			items.push_front(f);
			totalPrice += f.price;
		}
	}
	void printOrder() {
		cout << "===============Order===============" << endl;
		int i = 1;
		for (list<Food>::iterator it = items.begin(); it != items.end(); it++, i++) {
			Food f = *it;
			cout << i << ": " << f.name << ' ' << f.price << endl;
		}
		cout << "total: " << totalPrice << endl;
		cout << "===================================" << endl;
	}
};