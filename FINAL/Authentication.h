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
   int entered_ID; // Holds user entered ID during login prompt.
   string entered_PW; // Holds user entered password during login prompt.
   bool logged_in = false; // Identifies whether the current user is logged-in.
   const bool check_PW(GuestAccount &);
public:
   Authentication() { entered_ID = -1;  entered_PW = " "; }
   void get_IDPW();
   const bool get_Status() const;
   const int get_entered_ID() const ;
   const string get_entered_PW() const;
   const int login(DatabaseTree<GuestAccount> &, GuestAccount &);
   const bool check_ID(GuestAccount &, DatabaseTree<GuestAccount> &);
   const int registrationAutoLogin(GuestAccount &);
   void logout();
};

/* get_IDPW():
   - To be called by method - login, as well as method - registrationForm() of Registration, to obtain user's login credential.
 Parameter: None.
 Return: None.
*/
void Authentication::get_IDPW() {
   cout << "User ID: ";    cin >> entered_ID;
   cout << "Password: ";   cin >> entered_PW;
}

/*
 get_Status(): Allows user's login status to be retrieved.
 Parameter: None.
 Return: login status of type const boolean.
*/
const bool Authentication::get_Status() const { return logged_in; }

/* get_entered_ID():
   - Allows ID entered by the user to be retrieved by the Registration mehtod - registrationForm().
 Parameter: None.
 Return: user entered ID of type const boolean.
*/
const int Authentication::get_entered_ID() const { return entered_ID; }

/* get_entered_PW():
   - Allows password entered by the user to be retrieved by the Registration mehtod registrationForm().
 Parameter: None.
 Return: user entered password of type const boolean.
*/
const string Authentication::get_entered_PW() const { return entered_PW; }

/* check_ID(GuestAccount &, DatabaseTree<GuestAccount> &):
   - Handles checking of user entered ID with current GuestAccount in the account database tree.
 Parameter:
   - &for_acct: of type GuestAccount, the account to be checked.
   - &in_acct_DB: of type GuestAccount tree, the account database to be searched for the ID.
 Return: of type const boolean, result of database search.
*/
const bool Authentication::check_ID(GuestAccount &for_acct, DatabaseTree<GuestAccount> &in_acct_DB) {
   return in_acct_DB.search(for_acct);
}

/* check_PW(GuestAccount &):
   - Called after ID check is successful, to handle checking of user entered password.
 Parameter:
   - &for_registered: the user's registered account to be checked with user's entered password.
 Return: of type const boolean of the check result, false if check failed and user gives up correcting his/ her password.
*/
const bool Authentication::check_PW(GuestAccount &for_registered){
   bool retry = true;     /**/     bool match = false;
   while (!(match = (entered_PW == for_registered.get_Password())) && 1 == retry) {
      cout << "Password Incorrect! Retry(1/0)? ";     cin >> retry;
      if (1 == retry) { cout << "Password: ";   cin >> entered_PW; }
      else { cout << "You've chosen to abort login\n\n";}
   }
   return match;
}

/* login(DatabaseTree<GuestAccount> &, GuestAccount &):
 - Handles the login process by first calling get_IDPW(), then check_ID. If check_ID is successful, calls check_PW. If check password is successful, display user profile, sets login status to true.
 Parameter:
   - &in_acct_DB: Account database to be searched for matching account with user entered ID obtained by the get_IDPW(), and provides the ID matching account so that user entered password can be checked with the matching account.
   - &for_acct: A GuestAccount object to hold the matched user account content.
 Return: of type const int, the correct user entered ID, or -1 if user failed and give up entering the correct ID.
*/
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

/* registrationAutoLogin(GuestAccount &, DatabaseTree<GuestAccount> &):
   - Handles auto login for newly registered user.
 Parameter:
   - &for_new_acct: of type GuestAccount, whose stored ID is to be used for login.
 Return: userID.
*/
const int Authentication::registrationAutoLogin(GuestAccount &for_new_acct) {
   cout << "\nRegistration Auto Login!\n";
   entered_ID = for_new_acct.get_ID();
   entered_PW = for_new_acct.get_Password();
   logged_in = true;
   return entered_ID;
}

/* logout()
   - Handles account logout by setting logged-in status to false.
 Parameter: None.
 Return: None.
*/
void Authentication::logout() {
   cout << "Logging out\n\n";   logged_in = false;
}

#endif /* Authentication_h */


