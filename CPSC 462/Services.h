#include <iostream>
#include "room.h"

using namespace std;

struct staff
{
  string fname;
  string lname;
  staff(string fname = "", string lname= "") {
    this->fname = fname;
    this->lname = lname;
  }
};

class Services {
  private:
  vector < staff >  Allcleaners;
  vector < room >   notCleanedRoomvector;
  HouseKeeping      myHouseKeeping;

  public:
    bool clean(int index) {
      notCleanedRoomvector = myHouseKeeping.retNeedToBeCleanedVector();
        staff new_staff = getCleaner();
        if (new_staff.fname != ""){
        sendCleaner(new_staff,index);
        return 1;
    }else{
        return 0;
    }
    }

  void addCleaner(staff new_staff) {
    cout << endl << new_staff.fname << " " << new_staff.lname << "  you have been added to our team." << endl;
    Allcleaners.push_back(new_staff);
  }

  void removeCleaner(staff ex_staff) {
    bool found = false;
    bool deleteit =  false;
    for (int i = 0; i < Allcleaners.size(); i++) {
      if (Allcleaners[i].fname == ex_staff.fname && Allcleaners[i].lname == ex_staff.lname) {
        cout << endl << "You have been terminated: " << ex_staff.fname << " " << ex_staff.lname << endl << " .";
        deleteit = true;

      }
      if (deleteit) {
        Allcleaners.erase(Allcleaners.begin() + i);
        deleteit = false;
        found = true;
        }
    }
if (!found)
{
cout << endl  << ex_staff.fname << " " << ex_staff.lname << " is not one of our staff." << endl ;
}

  }

  staff getCleaner() {
    srand(time(0));
    if (Allcleaners.size() != 0 ){
    int index = rand() % Allcleaners.size();
    return Allcleaners[index];
    }
    else{
        staff nostaff("","");
     return nostaff;
    }
  }
  void sendCleaner(staff ready_staff, int index) {

    cout << endl << ready_staff.fname << " " << ready_staff.lname << ", you will be sent to clean the room number " << "( "<< index <<" )" << " shortly (be ready)" << endl;


  }

};
