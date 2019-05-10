#include "HouseKeepingController.h"
#include "check_reservation.h"

int getroomNum(int index){
    return index +1;
}


string MENU = "\n1.Add staff\n"
              "\n2.Remove staff\n"
              "\n3.clean a room\n\nEnter a number: ";

void  do_stuff_housekeeping()
 {


         vector<room> allRooms;
         check_reservation myreserv(1,1,1);
         allRooms = myreserv.send_roomlist();
         HouseKeepingController myHouseKeepingController;
         int roomNum = 0 ;
         int count = 0 ;


         int choice = 0 ;
         cout << MENU;
         cin >> choice;
         cin.ignore (1000,'\n');
while (true)
{

//roomNum = 0 ;
    if (choice > 0 && choice < 4 ){


        //cin.ignore(1000,' ');
        string fname;

        string lname;
        bool valid = false ;
        string f_name;
        switch(choice)
        {
        case 1:

            cout << "\nEnter the first name: ";
            getline (cin, fname);
            f_name = fname;
            cout << "\nEnter the last name: ";
            getline (cin, lname);
             myHouseKeepingController.addStaff(fname,lname);
            break;
        case 2:
            cout << "\nEnter the first name (removing): ";
            getline (cin, fname);
            cout << "\nEnter the last name(removing): ";
            getline (cin, lname);
            myHouseKeepingController.removeStaff(fname,lname);
            break;
        case 3 :
            roomNum = -1;
            cout << "\nWhich room do you want to be cleaned? ";
            cin  >> roomNum;
            if (allRooms.size() > roomNum-1 && roomNum-1 >= 0  && allRooms.size() != 0)
            {
                valid = true;
            }else
            {
                valid = false;
            }
            if (valid)
            {
                myHouseKeepingController.cleanARoom(allRooms[roomNum-1], roomNum);
            }
            else
            {
                cout << endl  << "The room you entered in not valid" << endl ;
            }
            break;
        default:
            break;

        }

        count ++;
    }else{
        cout << "\nyour choice is not valid.\n";
    }


    cout << MENU;
    cin >> choice;
    cin.ignore (1000,'\n');

    }


}


int main (){
    do_stuff_housekeeping();
    return 0 ;
}
