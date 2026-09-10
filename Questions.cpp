//
// Created by aka_wido0 on 9/10/26.
//
#include "Questions.h"
Questions::Questions() {
    Answerd = false;
    Answer = "";
    question = "";
    Sender = "";
    Receiver = "";
    id = -1;
    head_id = -1;
}

Questions::Questions(string txt, string sender, string Receive, int Id, int h_id) {
    question = txt;
    Sender = sender;
    Receiver = Receive;
    id = Id;
    Answerd = false;
    head_id = h_id;
}

void Questions::set_answer(string text) {
    Answer = text;
    Answerd = true;
}

int Questions::Get_headID() const {
    return head_id;
}

bool Questions::get_state() const {
    return Answerd;
}

const string& Questions::get_sender() const {
    return Sender;
}

const string& Questions::get_receiver() const {
    return Receiver;
}

void Questions::Show() const {
    cout << "ID: " << id << '\n';
    if (head_id == -1) cout << "Question: " << question << '\n';
    else cout << "thread from Question " << head_id << " : " << question << '\n';
    if (Answerd == true)
        cout << "Answer: " << Answer << '\n';
    else cout << "Answer: " << "Not Answerd yet!" << '\n';
    cout << "To: @" << Receiver << '\n';
}
