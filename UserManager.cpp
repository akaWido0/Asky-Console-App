//
// Created by aka_wido0 on 9/10/26.
//
#include "UserManager.h"

bool UserManager::Login(string username, string password) {
    auto user = users.find(username);
    if (user != users.end() && user->second.Get_Password() == password) {
        Current_User = user->second;
        return true;
    }
    return false;
}

bool UserManager::SignUP(string name, string username, string pass) {
    if (users.find(username) != users.end())
        return false;

    users.emplace(username, User(name, username, pass));
    return true;
}

const string& UserManager::Get_Name() const {
    return Current_User.Get_Name();
}

bool UserManager::Check_Username(string username) {
    return (users.find(username) != users.end());
}

const string& UserManager::Get_Username() const {
    return Current_User.Get_Username();
}

void UserManager::Show_Users() const {
    cout << "\n========== Users ==========\n";
    for (auto &[username, user] : users) {
        user.Show();
    }
}