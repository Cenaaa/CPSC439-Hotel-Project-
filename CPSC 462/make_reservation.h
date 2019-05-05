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
	make_reservation(int start, int end, int people);
	//~make_reservation();

private:
	int start_, end_, people_;
	bool picked_room, made_pay;
};

make_reservation :: make_reservation(int start, int end, int people)
{
	bool v_res = false;
	bool v_pay = false;

	check_reservation res(start, end, people);
	room z = res.check_res(start,end,people);
	while (v_res == false)
	{		
		if (z.get_id() == 0)
		{
			std::cout << "Room reservation failed." << std::endl;
			z = res.check_res(start,end,people);
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
			std:: cout << "Payment failed, try again." << std::endl;
		}
		else
		{
			res.change_reservation(z.get_id(),z.get_name(),start,end,people);
			v_pay = true;
		}
	}	
}

#endif 
