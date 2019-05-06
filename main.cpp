#include "check_reservation.h"
#include "HouseKeeping.h"
#include "Services.h"
#include "payment.h"
#include "payment_info.h"

int main ()
{
    vector<room> allRooms;
    check_reservation myreserv(1,1,1);
    allRooms = myreserv.send_roomlist();
    staff staff1("john"," jojo");
    staff staff2("rob"," ali");
    staff myCleaner("","");
    HouseKeeping myService;
    Services     obj;
    myService.request_To_Be_Cleaned(allRooms[0]);
    myService.request_To_Be_Cleaned(allRooms[1]);
    vector<room> notCleaned = myService.retNeedToBeCleanedVector();
    obj.addCleaner(staff1);
    obj.addCleaner(staff2);
    myCleaner = obj.getCleaner();
    obj.addCleaner(myCleaner);
    obj.sendCleaner(staff2);
    //obj.removeCleaner(staff2);






return 0;
}
