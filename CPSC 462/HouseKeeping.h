#include <iostream>
#include <ctime>
#include <vector>
#include "room.h"
#include <sys/time.h>
using namespace std;

class HouseKeeping {
private:
vector<room> notCleanedRoomsVector;
time_t now = time(0);

public:
    void request_To_Be_Cleaned (room newRoom)
    {
      notCleanedRoomsVector.push_back(newRoom);
    }
    void HasBeenCleaned(room newCleanedRoom)
    {
      notCleanedRoomsVector.pop_back();
    }

};
