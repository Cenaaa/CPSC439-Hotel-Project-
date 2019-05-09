//
//  main.cpp
//  462_Hotel
//
//  Created by Alex Liao on 2019/4/28.
//  Copyright © 2019年 Alex Liao. All rights reserved.

#include <string>
#include <fstream>
#include <iostream>
#include "User.h"
#include "Profile.h"
#include "payment_info.h"
#include "DatabaseTree.h"
#include "GuestAccount.h"
#include "Registration.h"
#include "Authentication.h"

#include "room.h"
#include "payment.h"
#include "payment_info.h"
#include "make_reservation.h"
#include "check_reservation.h"
#include "Services.h"
#include "HouseKeeping.h"
#include "KitchenController.h"

using std::string;
using std::cout;
using std::cin;

string site_features[] {"Quit", "Register", "Login", "Reservation", "Housekeeping", "Food Order", "Logout"};

void home_Menu();

/* CSUF
   657-278-2011
   800 N. State College Blvd. Fullerton, CA 92831
   CSUF@csu.fullerton.edu
   8
   1234
*/

int main(int argc, const char * argv[]) {
   int choice, usrID_Ref;
   Authentication auth;
   Registration acct_Register;
   GuestAccount registered;
   DatabaseTree<GuestAccount> account_DB;
   make_reservation mr;
   KitchenController kc;
   Services myService;
   HouseKeeping houseKeeping;

   staff staff1("john", " jojo");
   staff staff2("rob", " ali");

   do {
      GuestAccount new_acct;
      home_Menu();
      cin >> choice;
      cin.ignore();
      switch (choice) {
         case 1: // Create guest account
            if (auth.get_Status()) { // Check if the console that user is using to register is logged-in with someone else's account.
               cout << "You're logged-in. Please log-out to continue!\n\n";
               auth.logout();
               registered = NULL; // Clear prior logged-in user account to hold new user account.
            } else {
               cout << "New Account Registration!\n";
               acct_Register.registering(new_acct); // Beging registration process.
               if (-2 != new_acct.get_ID()) { // If account is successfully created.
                  if (acct_Register.update(account_DB, new_acct)) { // Update account database.
                     if (-1 != (usrID_Ref = auth.registrationAutoLogin(new_acct))) {
                        registered = new_acct;  /**/  new_acct = NULL;
                        cout << "Registered & Logged-in\n\n";
                     } else { cout << "Registration failed!\n\n"; }
                  }
               }
            }  break;
         case 2: // TO log-in: 1st, check if the use is already logged-in.
            if (auth.get_Status()) { cout << "Already logged-in!\n\n"; }
            else {
               usrID_Ref = auth.login(account_DB, registered);
               if (-1 == usrID_Ref) { cout << "Login failed!\n\n"; }
               else { cout << "You're logged-in!\n\n"; }
            }  break;
         case 3:  // Reservation
            if (auth.get_Status()) {
				 payment_info new_payment_info = mr.make_res(); 
				 registered.set_Payment_Info(new_payment_info);
            } else { cout << "Please login first!\n\n"; }
            break;
         case 4: // Housekeeping
            if (auth.get_Status()) {
               vector<room> allRooms;
               check_reservation myreserv(1, 1, 1);
               allRooms = myreserv.send_roomlist();
               staff staff1("john", " jojo");
               staff staff2("rob", " ali");
               staff myCleaner("", "");
               HouseKeeping myService;
               Services     obj;
               payment_info new_payment_info = registered.get_Payment_Info();
               int rm = new_payment_info.get_room();
               myService.request_To_Be_Cleaned(allRooms[rm - 1]);
               vector<room> notCleaned = myService.retNeedToBeCleanedVector();
               obj.addCleaner(staff1);
               obj.addCleaner(staff2);
               myCleaner = obj.getCleaner();
               obj.addCleaner(myCleaner);
               obj.sendCleaner(staff2);
               //obj.removeCleaner(staff2);
            } else { cout << "Please login first!\n\n"; }
            break;
         case 5:  // Food Order
            if (auth.get_Status()) {
				 payment_info new_payment_info = registered.get_Payment_Info();
				 int rm = new_payment_info.get_room();
				 kc.kitchenStuff(rm - 1);
            } else { cout << "Please login first!\n\n"; }
            break;
         case 6:  auth.logout(); break;
         case 0:  auth.logout(); break;
      }
   } while (0 != choice);
   return 0;
}

void home_Menu() {
   cout << "Select one of the following features\n";
   for (int ix = 0; ix < 7; ++ix) {
      cout << ix << ": " << site_features[ix] << endl;
   }
   cout << "Enter choice: ";
}
