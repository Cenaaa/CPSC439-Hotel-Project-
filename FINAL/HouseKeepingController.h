#ifndef housec
#define housec
#include "HouseKeeping.h"
#include "Services.h"
#include "string"
#include "room.h"


class HouseKeepingController
{
private:
    HouseKeeping myHouseKeeping;
    Services myService;

public:
    void cleanARoom(room newRoom, int roomNum)
    {
        myHouseKeeping.request_To_Be_Cleaned(newRoom);
        bool hasBeenOrganazied = myService.clean(roomNum);
        if (hasBeenOrganazied)
        {
            myHouseKeeping.HasBeenCleaned();
            cout << endl << "The room " << roomNum << " has been scheduled to be cleanned." << endl;
        }
        else
        {
            cout << endl
                 << "We do not have enough staff to clean any rooms at the moment (sorry!)."
                 << endl;
        }
    }

    void cancelOrder()
    {

        myHouseKeeping.HasBeenCleaned();
        // cout  << endl << "Your order to clean "<< roomNum  << " has been scheduled to be
        // cleanned."<< endl ;
    }

    void addStaff(string fnmae, string lname)
    {
        staff new_Staff(fnmae, lname);
        myService.addCleaner(new_Staff);
    }

    void removeStaff(string fnmae, string lname)
    {
        staff ex_Staff(fnmae, lname);
        myService.removeCleaner(ex_Staff);
    }
};
#endif