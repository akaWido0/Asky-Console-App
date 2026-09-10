//
// Created by aka_wido0 on 9/10/26.
//
static int Q_id=1;
#include "QuestionManager.h"

bool QeustionManager::Ask(string Sender, string reciver, string text, int head_id) {
    Questions Q(text, Sender, reciver, Q_id, head_id);
    bool is_correct_head = true;
    if (head_id == -1) {
        Threads[Q_id];
    }
    if (head_id != -1) {
        is_correct_head = (Threads.find(head_id) != Threads.end());
    }
    if (is_correct_head) {
        bool add = add_question_to_me(reciver, Q, Q_id, head_id);
        if (add) {
            add_question_from_me(Sender, Q, Q_id);
            Q_id++;
        }
        return add;
    }
    return false;
}

bool QeustionManager::answer_qustion(string reciver, int id, string text) {
    Questions* Q = GetQuestion_to_me(reciver, id);
    if (Q != nullptr) {
        bool state = Q->get_state();
        if (state) {
            cout << "\nThis Question is already Answerd\n";
            return false;
        }
        Q->set_answer(text);
        Questions* Q2 = GetQuestion_from_me(Q->get_sender(), id);
        if (Q2 != nullptr)
            Q2->set_answer(text);
        return true;
    }
    cout << "\nInvalid ID, try again!\n";
    return false;
}

bool QeustionManager::Delete_Question(string username, int id) {
    Questions *Q = GetQuestion_from_me(username, id);
    if (Q != nullptr) {
        int head = Q->Get_headID();
        if (head == -1) {
            for (auto th_id : Threads[id]) {
                Questions* th = GetQuestion_from_me(username, th_id);
                if (th != nullptr) {
                    string reciver = th->get_receiver();
                    Questions_from_me[username].erase(th_id);
                    Questions_to_me[reciver].erase(th_id);
                }
            }
            Threads.erase(id);
            string reciver = Q->get_receiver();
            Questions_from_me[username].erase(id);
            Questions_to_me[reciver].erase(id);
            return true;
        } else {
            Threads[head].erase(id);
            string reciver = Q->get_receiver();
            Questions_from_me[username].erase(id);
            Questions_to_me[reciver].erase(id);
            return true;
        }
    }
    return false;
}

bool QeustionManager::add_question_to_me(string username, Questions Q, int id, int head_id) {
    if (head_id != -1) {
        if (Questions_to_me[username].find(head_id) != Questions_to_me[username].end()) {
            Questions_to_me[username].emplace(id, Q);
            Threads[head_id].insert(id);
            return true;
        }
        return false;
    }
    Questions_to_me[username].emplace(id, Q);
    return true;
}

void QeustionManager::add_question_from_me(string username, Questions Q, int id) {
    Questions_from_me[username].emplace(id, Q);
}

Questions* QeustionManager::GetQuestion_to_me(const string& username, int id) {
    auto user_it = Questions_to_me.find(username);
    if (user_it == Questions_to_me.end())
        return nullptr;

    auto question_it = user_it->second.find(id);
    if (question_it == user_it->second.end())
        return nullptr;

    return &question_it->second;
}

Questions* QeustionManager::GetQuestion_from_me(const string& username, int id) {
    auto user_it = Questions_from_me.find(username);
    if (user_it == Questions_from_me.end())
        return nullptr;

    auto question_it = user_it->second.find(id);
    if (question_it == user_it->second.end())
        return nullptr;

    return &question_it->second;
}

bool QeustionManager::print_qustions_from_me(string username) {
    cout << "\n========== Questions from " << username << " ==========\n";
    if (!(Questions_from_me[username].empty())) {
        for (auto &[id, Q] : Questions_from_me[username]) {
            int head = Q.Get_headID();
            if (head == -1) {
                Q.Show();
                for (auto th_id : Threads[id]) {
                    Questions_from_me[username][th_id].Show();
                }
            }
        }
        cout << "-------------------------------\n";
        return true;
    }
    cout << "\nYou have no questions!\n";
    return false;
}

bool QeustionManager::print_qustions_to_me(string username, bool feed) {
    if (!Questions_to_me[username].empty()) {
        cout << "\n========== Questions to " << username << " ==========\n";
        for (auto &[id, Q] : Questions_to_me[username]) {
            int head = Q.Get_headID();
            if (head == -1) {
                Q.Show();
                for (auto th_id : Threads[id]) {
                    Questions_to_me[username][th_id].Show();
                }
            }
        }
        cout << "-------------------------------\n";
        return true;
    }
    if (!feed) cout << "\nYou have no questions!\n";
    return false;
}

void QeustionManager::Feed() {
    for (auto &[username, Qeus] : Questions_to_me) {
        print_qustions_to_me(username, true);
    }
}