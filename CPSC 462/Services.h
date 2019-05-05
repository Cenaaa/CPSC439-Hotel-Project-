#include <iostream>
#include "room.h"
#include "cleaners.h"
#include <queue>
using namespace std;




class Services : public HouseKeeping
{
private:
    queue<room> notCleanedRoomsQueue;
    queue<room> cleanedRoomsQueue;
    queue<Cleaners> readycleaner;
    queue<Cleaners> Allcleaners;

public:
    void clean()
    {
        if (notCleanedRoomsQueue.size()>1)
        {
            Cleaners staff = getCleaner();
            sendCleaner(staff);
        }


    }

    Clenears getCleaner()
    {
        readycleaner = Allcleaners.pop();
        return readycleaner.pop();
    }
    Clenears sendCleaner(Clenears staff)
    {
        cout << "/n/n" << staff.firstName << " " << staff.lastName << "will be sent to clean your room shortly./n/n";
    }
}
