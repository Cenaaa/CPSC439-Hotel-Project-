#ifndef checkres
#define checkres
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "payment.h"
#include "room.h"


class check_reservation
{
public: 
	check_reservation(int start, int end, int people);
	room check_res(int start, int end, int people);
	void change_reservation(int id, std::string name, int start, int end, int people);
	std::vector<room> send_roomlist();
	//~check_reservation();

private:
	std::vector<room> rooms;
	std::vector<room> non_reserved_rooms;
};

check_reservation::check_reservation(int start, int end, int people)
{	
	room a(1, 3, 500);
	rooms.push_back(a);
	room b("Bob Ross", 2, 5122019, 5202019, 4, 1000);
	rooms.push_back(b);
	room c("Bob Dylan", 3, 5152019, 5302019, 5, 2000);
	rooms.push_back(c);
	room d(4, 5, 3000);
	rooms.push_back(d);
	room e(5,3,250);
	rooms.push_back(e);


	
}

room check_reservation::check_res(int start, int end, int people)
{
	room n(0,0,0);
	for (int i = 0; i < 5; i++)
	{
		if (people <= rooms[i].get_people())
			{			
				if (start >= rooms[i].get_start() || rooms[i].get_start() == 0)
				{			
					std:: cout << "Room: " << rooms[i].get_id() << " is available." << std::endl;
					std:: cout << "Price: $" << rooms[i].get_price() << std::endl;		
					non_reserved_rooms.push_back(rooms[i]);
				}
			}		
	}

	if (non_reserved_rooms.size() == 0)
	{
		std:: cout << "No rooms available with those parameters." << std::endl;
		return n;
	}

	int choice;
	std::cout << "Choose a room." << std::endl;
	std::cin >> choice;
	for (int j = 0; j < rooms.size(); j++)
	{
		if (choice == non_reserved_rooms[j].get_id())
		{
			return rooms[j];
		}

	}
	std:: cout << "Didnt choose valid room." << std::endl;
	
	return n;
	

}

void check_reservation::change_reservation(int id, std::string name, int start, int end, int people)
{
	for (int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i].get_id() == id)
		{
			rooms[i].set_res(true);
			rooms[i].set_start(start);
			rooms[i].set_end(end);
			rooms[i].set_name(name);
		}
	}
}

std::vector<room> check_reservation::send_roomlist()
{
	return rooms;
}

#endif 
