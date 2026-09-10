//
// Created by aka_wido0 on 9/10/26.
//
#include <iostream>
#include "QuestionManager.h"
#include "UserManager.h"
#include "Helper.h"
using namespace std;
#ifndef ASKY_ASKYSYSTEM_H
#define ASKY_ASKYSYSTEM_H
class AskySystem {
    UserManager user_manager_;
    QeustionManager qeustion_manager_;
public:
    AskySystem();

   void LoginMenu();

   void SignUpMenu();

   void User_Menu();
};

#endif //ASKY_ASKYSYSTEM_H
