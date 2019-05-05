#include "KitchenController.h"

//0: finish order
//1: adding items
//2: deleting items


void KitchenController::kitchenStuff(int roomNum) {
	int c = -1;

	while (c != 0) {
		cout << "============================" << endl;
		cout << "Enter 0 to exit" << endl;
		cout << "Enter 1 to create an order" << endl;
		cout << "Enter 2 to check order status" << endl;
		cout << "Enter 3 to switch to kitchen" << endl;
		cin >> c;

		switch (c) {
		case 1: createOrder(roomNum); break;
		case 2: k.checkStatus(roomNum); break;
		case 3: k.kitchenMenu(); break;
		}
	}
}


void KitchenController::createOrder(int roomNum) {
	Menu m;
	m.initDummy();
	list<int> order;
	int c = 1;

	while (c != 0) {
		if (c == 1) {
			m.printMenu();
			cout << "Enter the number of the food you want" << endl;
			cout << "Enter 0 to complete order" << endl;
			int add = 1;
			while (add != 0) {
				cin >> add;
				order.push_front(add);
			}
			order.remove(order.front());

		}
		if (c == 2) {
			cout << "Enter the number of the food you want to remove" << endl;
			int d;
			cin >> d;
			list<int>::iterator it = order.end();
			advance(it, 0 - d);
			order.erase(it);
		}

		cout << "Is this order corect?" << endl;
		Order o = Order(order, m.kitMenu, roomNum);
		o.printOrder();

		cout << "Enter 0 to confirm" << endl;
		cout << "Enter 1 to add more items" << endl;
		cout << "Enter 2 to delete an item" << endl;
		cin >> c;

		if (c == 0) {
			k.addOrder(o);
			cout << "Order has been sent to the kitchen" << endl;
		}
	}
}