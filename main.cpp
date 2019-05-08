#include "HouseKeepingController.h"
#include "check_reservation.h"

int getroomNum(int index){
    return index +1;
}


string MENU = "\n1.Add staff\n"
              "\n2.Remove staff\n"
              "\n3.clean a room\n\nEnter a number: ";

int  main()
 {




         vector<room> allRooms;
         check_reservation myreserv(1,1,1);
         allRooms = myreserv.send_roomlist();
         HouseKeepingController myHouseKeepingController;

         int count = 0 ;

while (count < 5 )
{
    int choice = 0 ;
    int roomNum = 0 ;
    cout << MENU;
    cin >> choice;
    cin.ignore (1000,'\n');

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
         myHouseKeepingController.addStaff(f_name,lname);
        break;
    case 2:
        cout << "\nEnter the first name (removing): ";
        getline (cin, fname);
        cout << "\nEnter the last name(removing): ";
        getline (cin, lname);
        myHouseKeepingController.removeStaff(fname,lname);

        break;
    case 3 :
        cout << "\nWhich room do you want to be cleaned? ";
        cin  >> roomNum;
        if (allRooms.size() + 1 > roomNum && roomNum > 0 )
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
}
    //
    // //
    //  //myHouseKeepingController.addStaff("ho","ne");
    // // myHouseKeepingController.addStaff("hq","be");
    // // myHouseKeepingController.addStaff("hw","ae");
    // // myHouseKeepingController.addStaff("hr","se");
    //  myHouseKeepingController.addStaff("ht","ze");
    // // myHouseKeepingController.addStaff("hy","ee");
    // // myHouseKeepingController.addStaff("hi","xe");
    // // myHouseKeepingController.addStaff("hl","qe");
    // // myHouseKeepingController.addStaff("hh","we");
    // // myHouseKeepingController.addStaff("hg","re");
    // // myHouseKeepingController.addStaff("hc","ne");
    //
    // int index = 0 ;
    // int  roomNum  = getroomNum(index);
    // myHouseKeepingController.cleanARoom(allRooms[index],roomNum);
    //
    // myHouseKeepingController.removeStaff("ht", "ze");
    //
    // myHouseKeepingController.removeStaff("so", "so");
    //
    //
    //
    //
    //
    // myHouseKeepingController.addStaff("hy","ee");
    // myHouseKeepingController.addStaff("htw", "zew");
    // myHouseKeepingController.addStaff("hi","xe");
    // myHouseKeepingController.addStaff("na","ot");
    // myHouseKeepingController.addStaff("si","he");
    //
    //
    //
    // index = 2;
    // roomNum  = getroomNum(index);
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    // index = 4;
    // roomNum  = getroomNum(index);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    //
    // index = 2;
    // roomNum  = getroomNum(index);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    // myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    //
    //




return 0 ;
}
