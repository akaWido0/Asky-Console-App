//
// Created by aka_wido0 on 9/10/26.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include "Questions.h"
using namespace std;
#ifndef ASKY_QUESTIONMANAGER_H
#define ASKY_QUESTIONMANAGER_H

class QeustionManager {
    unordered_map<string,map<int,Questions>>Questions_to_me;   //Username to [id,Question]
    unordered_map<string,map<int,Questions>>Questions_from_me; //Username to [id,Question]
    unordered_map<int , set<int>> Threads;   // head_id to {Questions}
public:

    bool Ask(string Sender,string reciver,string text,int head_id);

    bool answer_qustion(string reciver , int id ,string text);

    bool Delete_Question(string username,int id);


    bool add_question_to_me(string username,Questions Q,int id,int head_id);

    void add_question_from_me(string username,Questions Q,int id);

    Questions* GetQuestion_to_me(const string& username, int id);

    Questions* GetQuestion_from_me(const string& username, int id);

    bool print_qustions_from_me(string username);

    bool print_qustions_to_me(string username,bool feed=0);

    void Feed();
};

#endif //ASKY_QUESTIONMANAGER_H
