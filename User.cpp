//
// Created by aka_wido0 on 9/10/26.
//
#include "User.h"

User::User() {
    Username = "", Name = "", Password = "";
}

User::User(string name, string username, string pass) {
    Name = name;
    Username = username;
    Password = pass;
}

const string& User::Get_Username() const {
    return Username;
}

const string& User::Get_Password() const {
    return Password;
}

const string& User::Get_Name() const {
    return Name;
}

void User::Show() const {
    cout << "Name: " << Name << '\n';
    cout << "Username: @" << Username << "\n";
    cout << "---------------------------\n";
}