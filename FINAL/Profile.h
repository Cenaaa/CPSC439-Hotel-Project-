//
//  Profile.h
//  462_Hotel
//
//  Created by Alex Liao on 2019/4/28.
//  Copyright © 2019年 Alex Liao. All rights reserved.

#ifndef Profile_h
#define Profile_h

#include <string>
using std::string;

// Holds user profile information, which is to be used during registration process.
struct Profile {
   int usrID;
   string password;
   string name;
   string phone;
   string address;
   string email;
};

#endif /* Profile_h */
