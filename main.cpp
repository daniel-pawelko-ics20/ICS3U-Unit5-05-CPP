// Copyright (c) 2022 Daniel Pawelko All rights reserved.
//
// Created by: Daniel Pawelko
// Created on: Jan 2022
// Address

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::transform;
using std::toupper;

string address(string name,
                string aptnum,
                string strnum,
                string strname,
                string city,
                string prov,
                string post) {
    // return formated address

    // define variable
    string formated;

    // process
    if (aptnum != "") {
        formated = name + "\n" + aptnum + "-" + strnum + " " + strname + "\n" +
            city + " " + prov + " " + post;
    } else {
        formated = name + "\n" + strnum + " " + strname + "\n" +
            city + " " + prov + " " + post;
    }

    // To upper
    transform(formated.begin(), formated.end(), formated.begin(),
                   [](unsigned char formated){ return toupper(formated); });

    return formated;
}

int main() {
    // main function for calling volume function

    // defining variables
    string temp = "";
    string name;
    string aptnum = "";
    string strnum;
    string strname;
    string city;
    string prov;
    string post;

    // details
    cout << "This program formats your address to a mailing address.";
    cout << endl;

    try {
        // input
        cout << "Enter your full name: ";
        getline(cin, name);

        cout << "Do you live in an apartment? (y/n): ";
        getline(cin, temp);

        if (temp == "y") {
            cout << "Enter your apartment number: ";
            getline(cin, aptnum);
        }

        cout << "Enter your street number: ";
        getline(cin, strnum);

        cout << "Enter your street name AND type (Main St, Express Pkwy...): ";
        getline(cin, strname);

        cout << "Enter your city: ";
        getline(cin, city);

        cout << "Enter your province (as an abbreviation, ex: ON, BC...): ";
        getline(cin, prov);

        cout << "Enter your postal code(123 456): ";
        getline(cin, post);

        // process/output
        cout << address(name, aptnum, strnum, strname, city, prov, post) endl;
    } catch (std::invalid_argument) {
        cout << "Input must be an integer" << endl;
    }

    // output finished
    cout << endl;
    cout << "Done." << endl;
}
