
#include "HouseKeepingController.h"
#include "check_reservation.h"




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
    int  roomNum  = index +1;
    myHouseKeepingController.cleanARoom(allRooms[index],roomNum);

    myHouseKeepingController.removeStaff("ht", "ze");

    myHouseKeepingController.cleanARoom(allRooms[index], roomNum);


    // staff staff1("john"," jojo");
    // staff staff2("rob"," ali");
    // staff staff3("rofsdasfafb"," fsd");
    // staff staff4("gogo"," wer");
    // staff staff5("josh"," balli");
    // staff myCleaner("","");
    //
    // myService.request_To_Be_Cleaned(allRooms[0]);
    // myService.request_To_Be_Cleaned(allRooms[1]);
    // vector<room> notCleaned = myService.retNeedToBeCleanedVector();
    // obj.addCleaner(staff1);
    // obj.addCleaner(staff2);
    // obj.addCleaner(staff3);
    // obj.addCleaner(staff4);
    // obj.addCleaner(staff5);
    // myCleaner = obj.getCleaner();
    // obj.sendCleaner(myCleaner);
    // myService.HasBeenCleaned();
    // myService.HasBeenCleaned();
    //
    // obj.removeCleaner(staff5);

return 0 ;
}
