#ifndef payinfo
#define payinfo
#include <string>

class payment_info
{
public:
	payment_info(std::string guest_name_, int bill_number_, int cc_ , int date_, int cw2_, int room_num_)
	{
		guest_name = guest_name_;
		bill_number = bill_number_;
		cc = cc_;
		date = date_;
		cw2 = cw2_;
		room_num = room_num_;
	}

	int get_cc()
	{
		return cc;
	}

	int get_bill()
	{
		return bill_number;
	}

	int get_cw2()
	{
		return cw2;
	}

	int get_date()
	{
		return date;
	}
	
private:
	std::string guest_name;
	int date,cw2, bill_number, cc, room_num;
};



#endif 
