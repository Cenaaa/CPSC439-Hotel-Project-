#include <iostream>
#include <string>
using namespace std;

struct staff
{
    string fname;
    string lname;
    staff(string fname, string lname){
      this.fname = fname;
      this.lname = lname;
    }
};


class Cleaners : public Services
{

private:

 vector<staff>  AllCleaners;


public:
   Cleaners(string fname = "", string lname="")
  {
      staff(fname,lname);

   }
   void addCleaner(staff new_staff)
   {
       cout << "/n you have been hired as a cleaner" << new_staff.fname << " " << new_staff.lname << "/n/n";
       Allcleaners.push_back(new_staff);
   }

   void removeCleaner(staff ex_staff)
   {
       bool deleteit;
       for (int i = 0 ; i < AllCleaners.size(); i++ )
       {
           if (AllCleaners[i].fname == ex_staff.fname &&  AllCleaners[i].lname == ex_staff.lname )
           {
               deleteit = false;
               cout << "/n you have been terminated." << ex_staff.fname << " " << ex_staff.lname;
                deleteit = true;

           }
           if (deleteit)
           {
              AllCleaners[i] = AllCleaners[i+1];
           }


       }
    AllCleaners.pop_back();
   }

};

