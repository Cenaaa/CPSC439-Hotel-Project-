#ifndef myres
#define myres
#include "check_reservation.h"
#include "payment.h"
#include "payment_info.h"

/*
*/
class make_reservation
{
public:
	make_reservation();
	payment_info make_res();
	//~make_reservation();

private:
	bool picked_room, made_pay;
};

make_reservation::make_reservation()
{
}

payment_info make_reservation::make_res()
{
	bool v_res = false;
	bool v_pay = false;
	int sdate, edate, ppl;

	std::cout << "You've selected make a reservation." << std::endl << "Enter a start date: ";
	std::cin >> sdate;
	std::cout << "Enter an end date: ";
	std::cin >> edate;
	std::cout << "Enter number of people: ";
	std::cin >> ppl;

	check_reservation res(sdate, edate, ppl);
	room z = res.check_res(sdate, edate, ppl);

	while (v_res == false)
	{
		if (z.get_id() == 0)
		{
			std::cout << "Room reservation failed." << std::endl;
			std::cout << "Enter a start date: ";
			std::cin >> sdate;
			std::cout << "Enter an end date: ";
			std::cin >> edate;
			std::cout << "Enter number of people: ";
			std::cin >> ppl;

			z = res.check_res(sdate, edate, ppl);
		}
		else
		{
			v_res = true;
		}
	}

	while (v_pay == false)
	{
		payment p(z.get_price());
		payment_info pi;
		pi = p.make_payment(z.get_id());

		if (pi.get_room() == 0)
		{
			std::cout << "Payment failed, try again." << std::endl;
		}
		else
		{
			res.change_reservation(z.get_id(), z.get_name(), sdate, edate, ppl);
			v_pay = true;
			return pi;
		}
	}

}



#endif 