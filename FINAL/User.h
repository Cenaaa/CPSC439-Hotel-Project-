//
//  User.h
//  462_Hotel
//
//  Created by Alex Liao on 2019/4/28.
//  Copyright © 2019年 Alex Liao. All rights reserved.

#ifndef User_h
#define User_h

#include <string>
using std::string;

// Abstract class for the GuestAccount to inherit from.
// Contains an abstract function that does not perform any functionality, but whose purpose is only make this class abstract.
class User {
protected:
   int usrID;
   string password;
   string name;
public:
   virtual void _() = 0;

};
#endif /* User_h */
