#include <iostream>
#include <string>
#include "make_reservation.h"
#include "check_reservation.h"

int main()
{
	int sdate,edate,ppl;

	//Ask for necessary info to make a reservation
	std::cout << "You've selected make a reservation." << std::endl << "Enter a start date: ";
	std::cin >> sdate;
	std::cout << "Enter an end date: ";
	std::cin >> edate;
	std::cout << "Enter number of people: ";
	std::cin >> ppl;

	make_reservation dab(sdate,edate,ppl);




	system("pause");
	return 0;
}