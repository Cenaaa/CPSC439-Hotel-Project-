#include <iostream>
#include "room.h"
#iclude "cleaners.h"
using namespace std;



class Services : public HouseKeeping
{
private:
    vector<room> notCleanedRoomvector;
    vector<staff> Allcleaners;

public:
    void clean()
    {
        if (notCleanedRoomvector.size()>1)
        {
            staff new_staff = getCleaner();
            sendCleaner(new_staff);
        }


    }

    staff getCleaner()
    {
        staff readycleaner = Allcleaners.pop_back();
        return readycleaner;
    }
    void sendCleaner(staff ready_staff)
    {
        cout << "/n/n" << ready_staff.fName << " " << ready_staff.lName << "will be sent to clean your room shortly./n/n";
    }
}
