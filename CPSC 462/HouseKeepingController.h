
#include "HouseKeeping.h"
#include "Services.h"
#include "string"
#include "room.h"




class HouseKeepingController
{
private:
HouseKeeping myHouseKeeping;
Services     myService;

public:


   void cleanARoom (room newRoom, int index)
   {
     myHouseKeeping.request_To_Be_Cleaned(newRoom);
     bool hasBeenOrganazied = myService.clean(index);
     if (hasBeenOrganazied){
       myHouseKeeping.HasBeenCleaned();
       cout  << endl << "The room is cleaned."<< endl ;
   }else{
       cout  << endl << "We do not have enough staff to clean any rooms at the moment (sorry!)."<< endl ;
   }
   }

   void addStaff(string fnmae,string lname)
   {
       staff new_Staff(fnmae,lname);
       myService.addCleaner(new_Staff);
   }

   void removeStaff(string fnmae,string lname)
   {
       staff ex_Staff(fnmae,lname);
       myService.removeCleaner(ex_Staff);
   }

};
