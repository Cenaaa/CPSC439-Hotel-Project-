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

class User {
protected:
   int usrID;
   string password;
   string name;
public:
   virtual void _() = 0;

};
#endif /* User_h */
