#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include "User.h"
#include "Utils.h"
#include "User_Menu.h"
#include "Admin_Menu.h"
#include "Menu.h"

using namespace std;

// This function handles the login screen preferences.
// "l" for login, "a" for admin panel, "r" for register panel
// "q" for quitting from whole program.
// For more information please visit the "User_Menu.h" or
// "Admin_Menu.h" files.
void Menu::login_screen_prefs(){

    string login_pref;
    while(true){
        getline(cin,login_pref);
        if(login_pref == "l"){
            User_Menu um;
            um.start("l");
        }
        if(login_pref == "a"){
            Admin_Menu am;
            am.start();
        }
        else if (login_pref == "r"){
            User_Menu um;
            um.start("r");
        }
        else if (login_pref == "q"){
            exit(0);
        }
        else {
            cout << "Wrong input. Please try again.";
            continue;
        }
    }
}

// This function prints a welcome panel and
// Prints the choices then calls login_screen_prefs
// function.
void Menu::login_screen(){

    time_t raw_time;
    struct tm * time_info;
    char buffer [80];
    time (&raw_time);
    time_info = localtime(&raw_time);
    cout << "-----------------------------------\n";
    cout << "|                                 |\n";
    cout << "|         Welcome again !         |\n";
    cout << "|                                 |\n";
    strftime (buffer,80,"|      %c   |",time_info);
    puts (buffer);
    cout << "|                                 |\n";
    cout << "|    Enter 'l' to login.          |\n";
    cout << "|          'a' to login as admin. |\n";
    cout << "|          'r' to register.       |\n";
    cout << "|          'q' to quit.           |\n";
    cout << "-----------------------------------\n";

    login_screen_prefs();
}

void Menu::start(){
    login_screen();
}
