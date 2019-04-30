#ifndef myres
#define myres
#include "check_reservation.h"

/*


*/
class make_reservation
{
public:
	make_reservation(int start, int end, int people);
	//~make_reservation();

private:
	int start_, end_, people_;
	bool picked_room;
};

make_reservation :: make_reservation(int start, int end, int people)
{
	check_reservation res(start, end, people);
	picked_room = res.check_res(start,end,people);

	if (picked_room == true)
	{
		std::cout << "Successfully picked room." << std::endl;
	}
 
}

#endif myres 