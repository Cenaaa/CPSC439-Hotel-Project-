#include <iostream>
#include <queue>
using namespace std;



class Cleaners : public Services

{
private:

    queue<Cleaners> Allcleaners;

public:
   void addCleaner(Cleaners staff)
   {
       cout << "/n you have been hired as a cleaner" << staff.fname << " " << staff.lname;
       Allcleaners.push(staff);
   }
   void removeCleaner(Cleaners staff)
   {
       cout << "/n you have been terminated." << staff.fname << " " << staff.lname;
       Allcleaners.poop(staff);
   }

};
