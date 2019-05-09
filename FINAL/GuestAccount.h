//
//  GuestAccount.h : This header file declares varios attributes of a guest account, and setter and getter methods to access and modify those attributes.
//  462_Hotel
//
//  Created by Alex Liao on 2019/4/28.
//  Copyright © 2019年 Alex Liao. All rights reserved.

#ifndef GuestAccount_h
#define GuestAccount_h

#include "User.h"
#include <string>
#include <iostream>
#include "payment_info.h"

using std::string;
using std::ostream;

// Inherits from the abstract User class.
class GuestAccount : public User {
   // Make ostream class operator << friend for access and overloading.
   friend ostream &operator<< (ostream &out, const GuestAccount account);
private:
   string phone;
   string address;
   string email;
   payment_info cc_info;
   
public:
   GuestAccount(int id = -2, string pw = " ", string nm = " ",
                string ph = " ", string addr = " ", string em = " ");
   GuestAccount &set_ID(int);
   GuestAccount &set_Password(string);
   GuestAccount &set_Name(string);
   GuestAccount &set_Phone(string);
   GuestAccount &set_Address(string);
   GuestAccount &set_Email(string);
   GuestAccount &set_Payment_Info(payment_info);
   const int    get_ID() const;
   const string get_Password() const;
   const string get_Name() const;
   const string get_Phone() const;
   const string get_Address() const;
   const string get_Email() const;
   const payment_info get_Payment_Info() const;
   
   // Overloaded comparison operators <, >, ==, only usrID will be looked at.
   bool operator<  (const GuestAccount &right) const;
   bool operator>  (const GuestAccount &right) const;
   bool operator== (const GuestAccount &right) const;
   
   void _(); // Do nothing, only implement abstract User.
   ~GuestAccount();
};
#endif /* GuestAccount_h */
