//
//  StayingGuest.h
//  462_Hotel
//
//  Created by Alex Liao on 2019/5/3.


#ifndef StayingGuest_h
#define StayingGuest_h

#include <string>
#include <iostream>
#include "GuestAccount.h"
using std::string;
using std::cout;
using std::cin;

class StayingGuest {
private:
   GuestAccount account;
   bool checked_in = false;
   int roomNumber;
public:
   StayingGuest(GuestAccount acct = NULL, int rm = -1);
   StayingGuest &set_GuestAccount(GuestAccount);
   StayingGuest &set_Room_Number(int);
   const  int   get_Room_Number() const;
   GuestAccount get_GuestAccount();
};

StayingGuest &StayingGuest::set_GuestAccount(GuestAccount acct) {
   account = acct;
   return (*this);
}

StayingGuest &StayingGuest::set_Room_Number(int rm) {
   roomNumber = rm;
   return (*this);
}

const int StayingGuest::get_Room_Number() const { return roomNumber; }
GuestAccount StayingGuest::get_GuestAccount() { return account; }

#endif /* StayingGuest_h */
