
#include "HouseKeeping.h"
#include <iostream>
#include <algorithm>
#include <iterator> // std::iterator, std::input_iterator_tag
#include "room.h"

using namespace std;

struct staff
{
    string fname;
    string lname;
    staff(string fname = "", string lname = "")
    {
        this->fname = fname;
        this->lname = lname;
    }
};

class Services
{
private:
    vector<staff> Allcleaners;
    vector<room> notCleanedRoomvector;
    HouseKeeping myHouseKeeping;
    int count = 0;

public:
    bool clean(int index)
    {
        notCleanedRoomvector = myHouseKeeping.retNeedToBeCleanedVector();
        staff new_staff = getCleaner();
        if (new_staff.fname != "")
        {
            sendCleaner(new_staff, index);
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void addCleaner(staff new_staff)
    {
        cout << endl
             << new_staff.fname << " " << new_staff.lname << "  you have been added to our team."
             << endl;
        Allcleaners.push_back(new_staff);
    }

    void removeCleaner(staff ex_staff)
    {
        vector<staff> modifiedCleaners;
        bool found = false;
        bool delIt = false;
        int j = 0;

        for (int i = 0; i < Allcleaners.size(); i++)
        {
            found = false;
            if (Allcleaners[i].fname == ex_staff.fname && Allcleaners[i].lname == ex_staff.lname)
            {
                found = true;
                delIt = true;
            }

            if (!found)
            {
                modifiedCleaners[j] = Allcleaners[i];
                j++;
            }
        }
        if (!delIt)
        {
            cout << endl
                 << ex_staff.fname << " " << ex_staff.lname << " is not one of our staff." << endl;
        }
        else
        {
            cout << endl
                 << "You have been terminated: " << ex_staff.fname << " " << ex_staff.lname << endl
                 << " .";
            Allcleaners.clear();
            for (int i = 0; i < modifiedCleaners.size(); i++)
            {
                Allcleaners[i] = modifiedCleaners[i];
            }
        }
    }

    staff getCleaner()
    {
        staff toBeSent("", "");
        if (count == Allcleaners.size() && Allcleaners.size() != 0)
        {
            count = 0;
            toBeSent = Allcleaners.at(0);
        }
        else
        {
            toBeSent = Allcleaners[count];
        }

        count++;

        return toBeSent;
    }

    void sendCleaner(staff ready_staff, int index)
    {
        cout << endl
             << ready_staff.fname << " " << ready_staff.lname
             << ", you will be sent to clean the room number "
             << "( " << index << " )"
             << " shortly (be ready)" << endl;
    }
};
