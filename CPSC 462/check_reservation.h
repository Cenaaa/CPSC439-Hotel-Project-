#ifndef checkres
#define checkres
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "payment.h"


class check_reservation
{
public: 
	check_reservation(int start, int end, int people);
	bool check_res(int start, int end, int people);
	//~check_reservation();

private:
	std::vector<std::string> rooms;
};

check_reservation::check_reservation(int start, int end, int people)
{	

}

bool check_reservation::check_res(int start, int end, int people)
{
	std::ifstream c_file("room_list.txt");
	std::string room_num;
	bool avail;
	

	if (!c_file)	
		std::cout << "Failed to open file." << std::endl;	
	else
	{
		std::string room,token, sdate, edate;
		int date, ppl;
		

		//Loop while there are lines to take in

		while ( std::getline(c_file, room) )
		{			
			std::stringstream ss(room);
			for (int j = 1; j < 5; j++)
			{
				std::getline(ss,token, ' ');
				
				if (j == 1)
				{					
					room_num = token;
				}

				else if(j == 2)
				{					
					ppl = stoi(token,nullptr,10);
				}

				else if (j == 3)
				{					
					sdate = token;
				}

				else if (j == 4)
				{					
					if (token != "Available")
					{	
						
						date = std::stoi(token,nullptr,10);	
										
					}
					else
						edate = token;		
				}
					

			}	

			if ((sdate == "Available" or start > date) and people <= ppl)
			{				
				rooms.push_back(room_num);
			}
			
		}

		c_file.close();
		if (rooms.size() == 0)
		{
			std:: cout << "No rooms are available. Please choose another date or number of people." << std::endl;
			return false;
		}
		else
		{	
			for (int i = 0; i < rooms.size(); i++)
			{
				std::cout << "Room " << i+1 << " is available." << std::endl;
			}

			std::cout << "Please select a room number." << std::endl;
			std::cout << "Press Q to cancel and choose different dates/people." << std::endl;
			std::string room_choice;
			std::cin >> room_choice;
			std::cin.clear();
			if (room_choice == "Q")
			{
				return false;
			}
			else
			{
				payment d;
				d.make_payment();
				return true;
			}
		}
	}
	return false;
}

#endif checkres