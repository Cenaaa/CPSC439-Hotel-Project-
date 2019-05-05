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
#include "Payment_Info.h"
#include "DatabaseTree.h"
#include "GuestAccount.h"
#include "StayingGuest.h"
#include "Registration.h"
#include "Authentication.h"

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
   do {
      GuestAccount new_acct;
      home_Menu();
      cin >> choice;
      cin.ignore();
      switch (choice) {
         case 1: // Create guest account
            if (auth.get_Status()) {
               cout << "You're logged-in. Please log-out to continue!\n\n";
               auth.logout();
               registered = NULL;
            } else {
               cout << "New Account Registration!\n";
               acct_Register.registering(new_acct);
               if (-2 != new_acct.get_ID()) {
                  if (acct_Register.update(account_DB, new_acct)) {
                     if (-1 != (usrID_Ref = auth.registrationAutoLogin(new_acct, account_DB))) {
                        registered = new_acct;  /**/  new_acct = NULL;
                        cout << "Registered & Logged-in\n\n";
                     } else { cout << "Registration failed!\n\n"; }
                  }
               }
            }  break;
         case 2: // TO log-in
            if (auth.get_Status()) { cout << "Already logged-in!\n\n"; }
            else {
               usrID_Ref = auth.login(account_DB, registered);
               if (-1 == usrID_Ref) { cout << "Login failed!\n\n"; }
               else { cout << "You're logged-in!\n\n"; }
            }  break;
         case 3:  if (auth.get_Status()) { }
                  else { cout << "Please login first!\n\n"; }
            break;
         case 4:  if (auth.get_Status()) { }
                  else { cout << "Please login first!\n\n"; }
            break;
         case 5:  if (auth.get_Status()) { }
                  else { cout << "Please login first!\n\n"; }
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
