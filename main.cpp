
#include "HouseKeepingController.h"
#include "check_reservation.h"

int getroomNum(int index){
    return index +1;
}


int  main()
 {



    vector<room> allRooms;
    check_reservation myreserv(1,1,1);
    allRooms = myreserv.send_roomlist();
    HouseKeepingController myHouseKeepingController;


    //
     //myHouseKeepingController.addStaff("ho","ne");
    // myHouseKeepingController.addStaff("hq","be");
    // myHouseKeepingController.addStaff("hw","ae");
    // myHouseKeepingController.addStaff("hr","se");
     myHouseKeepingController.addStaff("ht","ze");
    // myHouseKeepingController.addStaff("hy","ee");
    // myHouseKeepingController.addStaff("hi","xe");
    // myHouseKeepingController.addStaff("hl","qe");
    // myHouseKeepingController.addStaff("hh","we");
    // myHouseKeepingController.addStaff("hg","re");
    // myHouseKeepingController.addStaff("hc","ne");

    int index = 0 ;
    int  roomNum  = getroomNum(index);
    myHouseKeepingController.cleanARoom(allRooms[index],roomNum);

    myHouseKeepingController.removeStaff("ht", "ze");

    myHouseKeepingController.removeStaff("so", "so");





    myHouseKeepingController.addStaff("hy","ee");
    myHouseKeepingController.addStaff("htw", "zew");
    myHouseKeepingController.addStaff("hi","xe");
    myHouseKeepingController.addStaff("na","ot");
    myHouseKeepingController.addStaff("si","he");



    index = 2;
    roomNum  = getroomNum(index);
    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);

    index = 4;
    roomNum  = getroomNum(index);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);


    index = 2;
    roomNum  = getroomNum(index);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);
    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);






return 0 ;
}
