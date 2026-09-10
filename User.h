//
// Created by aka_wido0 on 9/10/26.
//
#include <iostream>
using namespace std;
#ifndef ASKY_USER_H
#define ASKY_USER_H
class User {
    string Username;
    string Name;
    string Password;

public:
    User();

    User(string name , string username , string pass);

    const string& Get_Username()const;

    const string& Get_Password()const;

    const string& Get_Name()const;

    void Show() const;
};

#endif //ASKY_USER_H
