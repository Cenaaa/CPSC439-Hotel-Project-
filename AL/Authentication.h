//
//  Authentication.h
//  462_Hotel
//
//  Created by Alex Liao on 2019/5/1.
//  Copyright © 2019年 Alex Liao. All rights reserved.
//

#ifndef Authentication_h
#define Authentication_h

#include <string>
#include <iostream>
#include "DatabaseTree.h"
#include "GuestAccount.h"

using std::string;
using std::cout;
using std::cin;

class Authentication {
private:
   int entered_ID;
   string entered_PW;
   bool logged_in = false;
   const bool check_PW(GuestAccount &);
public:
   Authentication() { entered_ID = -1;  entered_PW = " "; }
   void get_IDPW();
   const bool get_Status() const;
   const int get_entered_ID() const ;
   const string get_entered_PW() const;
   const int login(DatabaseTree<GuestAccount> &, GuestAccount &);
   const bool check_ID(GuestAccount &, DatabaseTree<GuestAccount> &);
   const int registrationAutoLogin(GuestAccount &, DatabaseTree<GuestAccount> &);
   void logout();
};

void Authentication::get_IDPW() {
   cout << "User ID: ";    cin >> entered_ID;
   cout << "Password: ";   cin >> entered_PW;
}

const bool Authentication::get_Status() const { return logged_in; }
const int Authentication::get_entered_ID() const { return entered_ID; }
const string Authentication::get_entered_PW() const { return entered_PW; }

const int Authentication::login(DatabaseTree<GuestAccount> &in_acct_DB, GuestAccount &for_acct) {
   char retry = 'n';
   get_IDPW();
   
   do {
      for_acct.set_ID(entered_ID);
      if (check_ID(for_acct, in_acct_DB)){
         for_acct = in_acct_DB.retrieve(for_acct);
         if (check_PW(for_acct)) {
            cout << endl << for_acct;
            logged_in = true;  return entered_ID; }
      } else { cout << "ID Incorrect! Retry(y/Y)? ";  cin >> retry; }
      if ('Y' == toupper(retry)) { get_IDPW(); }
   } while ('Y' == toupper(retry));
   
   return -1;
}

const int Authentication::registrationAutoLogin(GuestAccount &for_new_acct,
                                                DatabaseTree<GuestAccount> &in_acct_DB) {
   cout << "\nRegistration Auto Login!\n";
   entered_ID = for_new_acct.get_ID();
   entered_PW = for_new_acct.get_Password();
   logged_in = true;
   return entered_ID;
}

const bool Authentication::check_ID(GuestAccount &for_acct, DatabaseTree<GuestAccount> &in_acct_DB) {
   return in_acct_DB.search(for_acct);
}

const bool Authentication::check_PW(GuestAccount &for_registered){
   bool retry = true;     /**/     bool match = false;
   while (!(match = (entered_PW == for_registered.get_Password())) && 1 == retry) {
      cout << "Password Incorrect! Retry(1/0)? ";     cin >> retry;
      if (1 == retry) { cout << "Password: ";   cin >> entered_PW; }
      else { cout << "You've chosen to abort login\n\n";}
   }
   return match;
}

void Authentication::logout() {
   cout << "Logging out\n\n";   logged_in = false;
}

#endif /* Authentication_h */


