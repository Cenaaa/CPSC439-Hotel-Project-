#ifndef pment
#define pment
#include "payment_info.h"

class payment
{
public:
	payment(int price_);
	payment_info make_payment();
private:
	int price;
};
payment::payment(int price_)
{
	price = price_;
}

payment_info payment::make_payment()
{
	std::string name;
	int cw2, date,cc;

	std::cout << "Enter your name: ";
	std::getline(std::cin.ignore(),name);

	std::cout << "Enter your credit card number" << std::endl;
	std::cin >> cc;
	std::cout << "Enter the three whacky digits on the back of your card." << std::endl;
	std::cin >> cw2;
	std::cout << "Enter today's date: " << std::endl;
	std::cin >> date;

	std::cout << "Is the following information correct?" << std::endl;
	std::cout << "name: " << name << std::endl;
	std::cout << "cc: " << cc << std::endl;
	std::cout << "cw2: " << cw2 << std::endl;
	std::cout << "date: " << date << std::endl;

	std::string choice;
	std:: cin >> choice;

	if (choice == "y" or choice == "Y")
	{
		std::cout << "payment successful." << std::endl;
		payment_info f(name,123456+date,cc,date,cw2);
		return f;
	}
	else 
	{	
		std::cout << "no payment." << std::endl;
		payment_info n("",0,0,0,0);
		return n;
	}


}

#endif 
