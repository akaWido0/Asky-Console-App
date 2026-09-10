//
// Created by aka_wido0 on 9/10/26.
//
#include "AskySystem.h"

AskySystem::AskySystem() {
    while (true) {
        int ch;
        cout << "========== ASKY ==========\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Exit\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        ch = Choice(1, 3);
        cout << endl;
        if (ch == 1) {
            LoginMenu();
        } else if (ch == 2) {
            SignUpMenu();
        } else if (ch == 3) {
            break;
        }
    }
}

void AskySystem::LoginMenu() {
    while (true) {
        string username, password;
        cout << "\n========== Login ==========\n";
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;
        bool Login = user_manager_.Login(username, password);
        if (Login) {
            cout << "     \nWelcome " << user_manager_.Get_Name() << " in Asky\n";
            User_Menu();
            break;
        } else {
            cout << "     Invalid Username or Password!, try again\n";
            break;
        }
    }
}

void AskySystem::SignUpMenu() {
    string name, username, password;
    cout << "\n========== Register ==========\n";
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;
    bool Sign_Up = user_manager_.SignUP(name, username, password);
    if (Sign_Up)
        cout << "\nRegistration completed!, Return to Login\n";
    else
        cout << "Username already exists! Please choose another username\n";
}

void AskySystem::User_Menu() {
    string Current_username = user_manager_.Get_Username();
    while (true) {
        cout << "\n========== Menu ==========\n";
        cout << "1. Print Questions To Me\n";
        cout << "2. Print Questions From Me\n";
        cout << "3. Answer Question\n";
        cout << "4. Delete Question\n";
        cout << "5. Ask Question\n";
        cout << "6. Show Users\n";
        cout << "7. Feed\n";
        cout << "8. Logout\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        int ch = Choice(1, 8);
        if (ch == 1) {
            qeustion_manager_.print_qustions_to_me(Current_username);
        }
        if (ch == 2) {
            qeustion_manager_.print_qustions_from_me(Current_username);
        }
        if (ch == 3) {
            bool check = qeustion_manager_.print_qustions_to_me(Current_username);
            if (check) {
                int id;
                string text;
                cout << "\nEnter the ID of the question you want to answer: ";
                id = Check_int();
                if (id != -2) {
                    cout << "\nEnter your answer on this question : ";
                    cin.ignore();
                    getline(cin, text);
                    qeustion_manager_.answer_qustion(Current_username, id, text);
                }
            }
        }
        if (ch == 4) {
            bool check = qeustion_manager_.print_qustions_from_me(Current_username);
            if (check) {
                int id;
                cout << "\nEnter the Id of the question you want to Delete: ";
                id = Check_int();
                if (id != -2) {
                    bool Deleted = qeustion_manager_.Delete_Question(Current_username, id);
                    if (Deleted) cout << "\nQuestion has been Deleted Successfully\n";
                    else cout << "\nInvalid ID , try again!\n";
                }
            }
        }
        if (ch == 5) {
            string reciver, text;
            cout << "\n========== Ask Question ==========\n";
            cout << "Enter the username you want to ask: ";
            cin >> reciver;
            bool check = user_manager_.Check_Username(reciver);
            if (!check) {
                cout << "\nThis username does not exist! ,try again\n";
                continue;
            }
            if (reciver == Current_username) {
                cout << "\nYou cannot ask yourself!\n";
                continue;
            }
            int head_id;
            cout << "Enter the head Id to ask in thread , or -1 to not: ";
            head_id = Check_int();
            if (head_id != -2) {
                cout << "Enter your question: ";
                cin.ignore();
                getline(cin, text);
                bool done = qeustion_manager_.Ask(Current_username, reciver, text, head_id);
                if (done)
                    cout << "\nQuestion sent successfully!\n";
                else cout << "\nNo Question found with this head ID!\n";
            }
        }
        if (ch == 6) {
            user_manager_.Show_Users();
        }
        if (ch == 7) {
            cout << "\n========== Feed ==========\n";
            qeustion_manager_.Feed();
        }
        if (ch == 8) {
            break;
        }
    }
}