#include <iostream>
#include <ctime>
#include <queue>
#include "room.h"
#include <sys/time.h>
using namespace std;

class HouseKeeping {
private:
queue<room> notCleanedRoomsQueue;
queue<room> cleanedRoomsQueue;
time_t now = time(0);

public:
    void request_To_Be_Cleaned (room newRoom)
    {
      notCleanedRoomsQueue.push(newRoom);
    }
    void HasBeenCleaned(room newCleanedRoom)
    {
      cleanedRoomsQueue.push(newCleanedRoom);
      notCleanedRoomsQueue.pop(newCleanedRoom);
    }
    void UpdateRoomStat ()
    {
        for(int i = 0 ; i < cleanedRoomsQueue.size(); i ++  )
        {
          if (cleanedRoomsQueue.room.DateClean - now > 48 * 60 * 60)
          {

                       cleanedRoomsQueue.pop(room);
                       notCleanedRoomsQueue.push(room);
          }
        }
    }
};
