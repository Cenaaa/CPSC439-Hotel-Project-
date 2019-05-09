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

/* set_ID(int)
   - Setter function to set the account ID.
 Parameter:
 - id: of type int. The value to be set as the account ID.
 Return: pointer to GuestAccount object itself.
*/
GuestAccount &GuestAccount::set_ID(int id) {
   this->usrID = id;
   return (*this);
}

/* set_Password(string)
   - Setter function to set the password to access the account.
 Parameter:
   - pw: of type string. The value to be set as the account password.
 Return: pointer to GuestAccount object itself.
*/
GuestAccount &GuestAccount::set_Password(string pw) {
   this->password = pw;
   return (*this);
}

/* set_Name(string)
   - Setter function to set the name of the account user.
 Parameter:
   - nm: of type string.
 Return: pointer to GuestAccount object itself.
*/
GuestAccount &GuestAccount::set_Name(string nm) {
   this->name = nm;
   return (*this);
}

/* set_Phone(string)
   - Setter function to set the phone number of the account user.
 Parameter:
   - ph: of type string.
 Return: pointer to GuestAccount object itself.
 */
GuestAccount &GuestAccount::set_Phone(string ph) {
   phone = ph;
   return (*this);
}

/* set_Address(string)
   - Setter function to set the mailing address of the account user.
 Parameter:
   - addr: of type string.
 Return: pointer to GuestAccount object itself.
 */
GuestAccount &GuestAccount::set_Address(string addr) {
   address = addr;
   return (*this);
}

/* set_Email(string)
   - Setter function to set the Email address of the account user.
 Parameter:
   - em: of type string.
 Return: pointer to GuestAccount object itself.
 */
GuestAccount &GuestAccount::set_Email(string em) {
   email = em;
   return (*this);
}

/* set_Payment_Info(payment_info)
   - Setter function to set the payment method information of the account user.
 Parameter:
   - cc_: of type payment_info.
 Return: pointer to GuestAccount object itself.
*/
GuestAccount &GuestAccount::set_Payment_Info(payment_info cc_) {
   cc_info = cc_;
   return (*this);
}

/* Following are getter functions to return the value of attributes of the class.
 Parameter: None.
 Return: Associated attribute type.
*/
const int    GuestAccount::get_ID() const { return this->usrID; }
const string GuestAccount::get_Password() const { return this->password; }
const string GuestAccount::get_Name() const { return this->name; }
const string GuestAccount::get_Phone() const { return this->phone; }
const string GuestAccount::get_Address() const { return this->address; }
const string GuestAccount::get_Email() const { return this->email; }
const payment_info GuestAccount::get_Payment_Info() const { return this->cc_info; }

/* Following are overloaded comparison operators <, >, ==, only usrID will be compared.
*/
bool GuestAccount::operator<  (const GuestAccount &right) const {
   return (this->usrID < right.get_ID());
}
bool GuestAccount::operator>  (const GuestAccount &right) const {
   return (this->usrID > right.get_ID());
}
bool GuestAccount::operator== (const GuestAccount &right) const {
   return (this->usrID == right.get_ID());
}

/* &operator<< (ostream &, const GuestAccount)
   - Overloaded output stream operator to print out user profile information.
 Usage: Simply use this operator with object of type GuestAccount. i.e. cout << GuestAccount;
 Parameter:
   -&out: of type ostream.
   -account: of type GuestAccount.
 Returen: ostream object - out.
*/
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

