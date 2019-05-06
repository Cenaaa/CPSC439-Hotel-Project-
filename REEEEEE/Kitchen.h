#include "Order.h"

class Kitchen {
public:
	Order orders[100];
	int orderCounter = 0;

	Kitchen() {

	}
	
	void addOrder(Order o) {
		orders[orderCounter] = o;
		orderCounter++;
	}

	void printOrder(Order o, int num) {
		cout << "Order #" << num << " for room " << o.roomNum << ": ";
		for (list<Food>::iterator it = o.items.begin(); it != o.items.end(); it++) {
			Food f = *it;
			cout << f.name << ", ";
		}
		cout << endl << "Status: " << o.status << endl;
	}

	void seeOrders() {
		for (int i = 0; i < orderCounter; i++) {
			printOrder(orders[i], i);
		}
	}

	void checkStatus(int roomNum) {
		for (int i = 0; i < 100; i++) {
			if (orders[i].roomNum == roomNum) {
				printOrder(orders[i], i);
			}
		}
	}

	void updateOrder() {
		cout << "Enter the number of the order to update" << endl;
		int i;
		cin >> i;
		if (orders[i].status.compare("ordered") == 0) {
			orders[i].status = "cooking";
			cout << "Order " << i << " has been updated to 'cooking'" << endl;
		}else if (orders[i].status.compare("cooking") == 0) {
			orders[i].status = "delivered";
			cout << "Order " << i << " has been updated to 'delivered'" << endl;
		}

	}

	void kitchenMenu() {
		int c = -1;
		while (c != 0) {
			cout << "============================" << endl;
			cout << "Enter 0 to exit" << endl;
			cout << "Enter 1 to see orders" << endl;
			cout << "Enter 2 to update an order" << endl;
			cin >> c;
			switch (c) {
			case 1: seeOrders(); break;
			case 2:updateOrder(); break;
			}
		}
	}
};