//
// Created by aka_wido0 on 9/10/26.
//
#include "Helper.h"
int Check_int() {
    int ch;
    if (!(cin >> ch)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input! Please enter a number\n";
        return -2;
    }
    return ch;
}

int Choice(int l,int r) {
    int ch = Check_int();
    if (ch!=-2 && (ch>r||ch<l)) {
        cout<<endl<<"Invalid Choice\n";
        return -1;
    }
    return ch;
}
