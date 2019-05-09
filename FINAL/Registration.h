//
//  Registration.h
//  462_Hotel
//  Created by Alex Liao on 2019/5/3.
//  Copyright © 2019年 Alex Liao. All rights reserved.

#ifndef Registration_h
#define Registration_h

#include <string>
#include <iostream>
#include "Profile.h"
#include "DatabaseTree.h"
#include "GuestAccount.h"
#include "Authentication.h"

using std::string;
using std::cout;
using std::cin;

class Registration {
private:
   Profile profile; // To hold user entered profile information.
   Authentication auth; // Object to handle login process.
   void registrationForm();
   void create_acct(GuestAccount &);
public:
   Registration();
   void registering(GuestAccount &);
   bool update(DatabaseTree<GuestAccount> &, GuestAccount &);
};

Registration::Registration() { }

/*
 registering(GuestAccount &): Called in main.cpp to begin the account registration process.
 Parameter: of type GuestAccount empty object passed-in to be initialized with profile information.
 Return: None.
*/
void Registration::registering(GuestAccount &new_acct) {
   registrationForm();
   create_acct(new_acct);
}

/*
 registrationForm(): Called by method - registering to obtain user profile information.
 parameter: None.
 Return: None
*/
void Registration::registrationForm() {
   cout << "Name: ";    getline(cin, profile.name);
   cout << "Phone: ";   getline(cin, profile.phone);
   cout << "Address: "; getline(cin, profile.address);
   cout << "Email: ";   getline(cin, profile.email);
   auth.get_IDPW();
   profile.usrID = auth.get_entered_ID();
   profile.password = auth.get_entered_PW();
}

/*
 create_acct(GuestAccount &new_acct): Called by method - registering after profile information is obtained to initialize the empty GuestAccount object.
 Parameter: new_acct - of type GuestAccount passed-in by value.
 Return: None.
*/
void Registration::create_acct(GuestAccount &new_acct) {
   new_acct.set_ID(profile.usrID);
   new_acct.set_Password(profile.password);
   new_acct.set_Name(profile.name);
   new_acct.set_Phone(profile.phone);
   new_acct.set_Address(profile.address);
   new_acct.set_Email(profile.email);
}

/*
 update(DatabaseTree<GuestAccount> &, GuestAccount &): Called in main.cpp to update the account database after sucessful initialization of new GuestAccount object.
 Parameter:
 - in_DB: Account database in the form of binary tree passed-in by value from main.cpp.
 - with_acct: The GuestAccount object to be inserted into the account database tree.
*/
bool Registration::update(DatabaseTree<GuestAccount> &in_DB, GuestAccount &with_acct) {
   bool retry = true;    /**/    bool id_found = false;
   do {
      if (auth.check_ID(with_acct, in_DB))
      { cout << "Account exist! Retry (1/0): ";   cin >> retry; }
      else {
         id_found = false;    retry = false;
         return in_DB.insert(with_acct);
      }
      if (!retry) {
         cout << "User ID: ";    cin >> profile.usrID;
         with_acct.set_ID(profile.usrID);
      }
   } while (id_found && retry);
   return false;
}

#endif /* Registration_h */
