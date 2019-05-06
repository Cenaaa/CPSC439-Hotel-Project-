#include <iostream>
//#include "room.h"
#include "HouseKeeping.h"
//using namespace std;


struct staff
{
    string fname;
    string lname;
    staff(string fname, string lname){
      this->fname = fname;
      this->lname = lname;
    }
};



class Services
{
private:
    vector<staff> Allcleaners;
    vector<room> notCleanedRoomvector;
    HouseKeeping obj;

public:
    void clean()
    {
        notCleanedRoomvector = obj.retNeedToBeCleanedVector();
        if (notCleanedRoomvector.size() > 1)
        {
            staff new_staff = getCleaner();
            sendCleaner(new_staff);
        }
    }

    void addCleaner(staff new_staff)
    {
		cout << endl << " you have been hired as a cleaner" << new_staff.fname << " " << new_staff.lname << endl;
        Allcleaners.push_back(new_staff);
    }

    void removeCleaner(staff ex_staff)
    {
        bool deleteit;
        for (int i = 0 ; i < Allcleaners.size(); i++ )
        {
            if (Allcleaners[i].fname == ex_staff.fname &&  Allcleaners[i].lname == ex_staff.lname )
            {
                deleteit = false;
                cout << "/n you have been terminated." << ex_staff.fname << " " << ex_staff.lname;
                 deleteit = true;

            }
            if (deleteit)
            {
               Allcleaners[i] = Allcleaners[i+1];
            }


        }
     Allcleaners.pop_back();
    }


    staff getCleaner()
    {
        staff readyCleaner = Allcleaners.back();
                           Allcleaners.pop_back(); 
        return readyCleaner;
    }
    void sendCleaner(staff ready_staff)
    {
        cout << "/n/n" << ready_staff.fname << " " << ready_staff.lname << "will be sent to clean your room shortly./n/n";
    }







};
