#ifndef payinfo
#define payinfo
#include <string>

class payment_info
{
public:
	payment_info(std::string guest_name_, std::string bill_number_, std::string cc_ , int date_, int cw2_)
	{
		guest_name = guest_name_;
		bill_number = bill_number_;
		cc = cc_;
		date = date_;
		cw2 = cw2_;
	}
	
private:
	std::string guest_name, bill_number, cc;
	int date,cw2;
};



#endif payinfo