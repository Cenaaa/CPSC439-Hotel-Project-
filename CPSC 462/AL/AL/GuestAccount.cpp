//
//  GuestAccount.cpp
//  462_Hotel
//
//  Created by Alex Liao on 2019/4/28.
//  Copyright © 2019年 Alex Liao. All rights reserved.
//

#include "GuestAccount.h"

GuestAccount::GuestAccount(int id, string pw, string nm, string ph, string addr, string em) {
   set_ID(id);
   set_Password(pw);
   set_Name(nm);
   set_Phone(ph);
   set_Address(addr);
   set_Email(em);
}

GuestAccount &GuestAccount::set_ID(int id) {
   this->usrID = id;
   return (*this);
}

GuestAccount &GuestAccount::set_Password(string pw) {
   this->password = pw;
   return (*this);
}

GuestAccount &GuestAccount::set_Name(string nm) {
   this->name = nm;
   return (*this);
}

GuestAccount &GuestAccount::set_Phone(string ph) {
   phone = ph;
   return (*this);
}

GuestAccount &GuestAccount::set_Address(string addr) {
   address = addr;
   return (*this);
}

GuestAccount &GuestAccount::set_Email(string em) {
   email = em;
   return (*this);
}

GuestAccount &GuestAccount::set_Payment_Info(Payment_Info cc_) {
   cc_info = cc_;
   return (*this);
}

const int    GuestAccount::get_ID() const { return this->usrID; }
const string GuestAccount::get_Password() const { return this->password; }
const string GuestAccount::get_Name() const { return this->name; }
const string GuestAccount::get_Phone() const { return this->phone; }
const string GuestAccount::get_Address() const { return this->address; }
const string GuestAccount::get_Email() const { return this->email; }
const Payment_Info GuestAccount::get_Payment_Info() const { return this->cc_info; }

bool GuestAccount::operator<  (const GuestAccount &right) const {
   return (this->usrID < right.get_ID());
}
bool GuestAccount::operator>  (const GuestAccount &right) const {
   return (this->usrID > right.get_ID());
}
bool GuestAccount::operator== (const GuestAccount &right) const {
   return (this->usrID == right.get_ID());
}

ostream &operator<< (ostream &out, const GuestAccount account) {
   out << "Name:    " << account.name     << std::endl
       << "User ID: " << account.usrID    << std::endl
       << "Phone:   " << account.phone    << std::endl
       << "Address: " << account.address  << std::endl
       << "Email:   " << account.email    << std::endl;
   return out;
}

void GuestAccount::_() { } // Neccessary to inherit from abstract User class.
GuestAccount::~GuestAccount() { }

