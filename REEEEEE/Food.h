#include <iostream>
#include <string>
#include <list>
using namespace std;

class Food {
public:
	int price;
	string name;
	Food(string myName, int myPrice) {
		price = myPrice;
		name = myName;
	}
	bool operator == (const Food &Ref) const {
		return (this->name.compare(Ref.name) == 0);
	}
};