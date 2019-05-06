#ifndef r
#define r

class room
{
	public:
		room(int room_id_, int people_, int price_)
		{
			start_date = 0;
			end_date = 0;
			price = price_;
			room_id = room_id_;
			people = people_;
			bool reserved = false;
		}

		room(std::string guest_name_, int room_id_, int start_date_, int end_date_, int people_, int price_)
		{
			price = price_;
			people = people_;
			room_id = room_id_;
			guest_name = guest_name_;
			start_date = start_date_;
			end_date = end_date_;
			bool reserved = true;
		}

		bool is_clean()
		{
			return clean;
		}

		void set_clean(bool c)
		{
			clean = c;
		}

		bool is_reserved()
		{
			return reserved;
		}

		void set_res(bool res)
		{
			reserved = res;
		}

		int get_id()
		{
			return room_id;
		}

		int get_start()
		{
			return start_date;
		}

		int get_end()
		{
			return end_date;
		}

		std::string get_name()
		{
			return guest_name;
		}

		int get_people()
		{
			return people;
		}

		int get_price()
		{
			return price;
		}

		void set_start(int s)
		{
			start_date = s;
		}

		void set_end(int e)
		{
			end_date = e;
		}

		void set_name(std::string name)
		{
			guest_name = name;
		}

		

	private:
		int room_id, start_date, end_date, people, price;
		std::string guest_name;
		bool clean, reserved;


};

#endif
