//
// Created by aka_wido0 on 9/10/26.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include "User.h"
using namespace std;
#ifndef ASKY_USERMANAGER_H
#define ASKY_USERMANAGER_H

class UserManager {
    User Current_User;
    unordered_map<string,User>users;
public:

    bool Login(string username , string password);


    bool SignUP(string name , string username , string pass);

    const string& Get_Name () const ;

    bool Check_Username(string username);

    const string& Get_Username() const;

    void Show_Users() const;
};

#endif //ASKY_USERMANAGER_H
