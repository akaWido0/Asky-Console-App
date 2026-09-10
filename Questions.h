//
// Created by aka_wido0 on 9/10/26.
//
#include <iostream>
using namespace std;
#ifndef ASKY_QUESTIONS_H
#define ASKY_QUESTIONS_H
class Questions {
    int id;
    string Answer;
    string question;
    string Sender;
    string Receiver;
    int head_id;
    bool Answerd;

public:
    Questions();

    Questions(string txt , string sender , string Receive,int Id,int h_id);

    void set_answer(string text);

    int Get_headID() const;

    bool get_state() const;

    const string& get_sender() const;

    const string& get_receiver() const;

    void Show() const;
};
#endif //ASKY_QUESTIONS_H
