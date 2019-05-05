#ifndef myres
#define myres
#include "check_reservation.h"
#include "payment.h"

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
	check_reservation res(start, end, people);
	room z = res.check_res(start,end,people);
	if (z.get_id() == 0)
	{
		std::cout << "bro you didnt get a valid room" << std::endl;
	}
	else
	{
		payment p(z.get_price());
		p.make_payment();
	}	
}

#endif 
