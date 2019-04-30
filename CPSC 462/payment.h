#ifndef pment
#define pment

class payment
{
public:
	payment();
	bool make_payment();
};
payment::payment()
{
}

bool payment::make_payment()
{
	std::string name, cc, bill;
	int cw2, date;

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
	std::cout << cw2 << std::endl;
	std::cout << date << std::endl;

	return true;

}

#endif pment