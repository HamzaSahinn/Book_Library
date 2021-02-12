#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Utils.h"
#include "Admin.h"
#include "Admin_Menu.h"

using namespace std;

// These two are the state variables.
int admin_screen_switch;
int book_archieve_switch;

struct log admin_login;
Admin admin;
Utils uti;

// This function transforms a "log" typed variable to a "Admin" object.
// returns: An Admin Object
Admin Admin_Menu::get_admin_infos(struct log t){
    Admin temp_admin;
    temp_admin.set_admin_serial_number(t.serial_num);
    temp_admin.set_admin_id(t.id);
    temp_admin.set_password(t.password);
    return temp_admin;
}

// This function read all admins' IDs and Passwords from the file. Then it asks user to
// enter their ID and Password. If it matches one account then it returns the a log object which contains admin
// information. If it is not matches any of the account then it returns a log object with serial number -1.
// It is the communication way of functions. Its mean is, if serial number is -1 then terminate program.
// returns: A log object.
struct log Admin_Menu::check_admin(){
    vector<struct log> vec_log;
    ifstream admin_ID_Passwords("../Admins_IDs_Passwords.txt");

    if (admin_ID_Passwords.is_open()) {
        string line;
        while (getline(admin_ID_Passwords, line)) {
            stringstream ss(line);
            vector<string> words;
            string word;
            while (getline(ss, word, ',')) {
                words.push_back(word);
            }
            struct log temp;
            temp.password = words.at(1);
            temp.id = words.at(0);
            stringstream s(words.at(2));
            s >> temp.serial_num;
            vec_log.push_back(temp);
        }
        admin_ID_Passwords.close();
    }
    else{
        cout <<"The admin_ID_Passwords.txt file could not be opened. Program terminating...";
        _sleep(2000);
        exit(3);
    }
    struct log admin;
    cout << "\n(Program will be terminated if you enter any incorrect input.)";
    cout << "\nPlease enter your admin ID: ";
    getline(cin, admin.id);
    cout << "\nPlease enter your password: ";
    getline(cin, admin.password);
    admin.serial_num = -1;

    for(int i = 0; i < vec_log.size(); ++i) {
        if (uti.compare_logs(vec_log.at(i), admin)){
            admin.serial_num = vec_log.at(i).serial_num;
            return admin;
        }
    }
    return admin;
}

// This function is similar to "browse_book_as_user function". But the actions are different.
// It prints the book summary and you can edit the price of the book.
// It takes two parameters first one is the valid Admin object  and the second one is the browsed book object.
void Admin_Menu::browse_book_as_admin(Admin ad, book current_book){


    cout << "Book ID    : " << current_book.getBookId() << endl;
    cout << "Book name  : " << current_book.getBookName() << endl;
    cout << "Writer     : " << current_book.getWriter() << endl;
    cout << "Publisher  : " << current_book.getPublisher() << endl;
    cout << "Page Number: " << current_book.getPageNumber() << endl;
    cout << "Price      : " << current_book.getPrice() << " TL\n";
    cout << "* " << current_book.getLikedNumber() << " people have liked this book.\n";
    cout << "* " << current_book.getReadNumber() << " people have read this book.\n\n";

    cout << "Enter 'e' to edit the price of " << current_book.getBookName() << ".\n";
    cout << "      'b' to go back to the book archive.\n";

    string c;
    while (true){
        getline(cin, c);
        if (c == "e"){
            string new_p;
            cout << "Please enter new price: ";
            getline(cin, new_p);
            float new_price = stof(new_p);
            cout << "Price of " << current_book.getBookName() << " is getting changed from " << current_book.getPrice() << " TL to "
                 << new_price << " TL. ";
            if(uti.make_choice()){
                uti.all_books.at(current_book.getBookId()-1).setPrice(new_price);
                cout << "\nBook archive has been updated...\n";
                _sleep(2000);
                book_archieve_switch = 1;
                break;
            }
            else{
                cout << "\nProcess got cancelled. Returning to browsing screen...\n";
                _sleep(2000);
                book_archieve_switch = 1;
                break;
            }
        }
        else if (c == "b"){
            book_archieve_switch = 1;
            break;
        }
        else {
            cout << "Wrong input. Please try again:\n";
        }
    }

}

// This function takes input to navigate you to a book page or admin screen.
// You can browse a book or go back to the admin screen.
void Admin_Menu::book_archieve_prefs(Admin ad) {
    cout << "Enter 'b' to browse a book.\n";
    cout << "      'a' to go back to the admin screen.\n";
    string a;
    getline(cin, a);
    if (a == "b"){
        string b;
        cout << "Enter the number of the book you would like to browse:";
        getline(cin, b);
        cout << endl;
        if (stoi(b) > 0 && stoi(b) < uti.all_books.size()+1)
            browse_book_as_admin(ad, uti.all_books.at(stoi(b)-1));
        else{
            cout << "Wrong input.\n";
            book_archieve_prefs(ad);
        }
    }
    else if (a == "a")
        admin_screen_switch = 1;
    else{
        cout << "Wrong input.\n";
        book_archieve_prefs(ad);
    }
}

// This function prints The books' names and calls "book_archieve_prefs"
// to navigate user.
void Admin_Menu::book_archieve(Admin ad){
    cout << "-------------------------\n";
    cout << "      Book Archieve      \n";
    cout << "-------------------------\n";

    uti.print_books(uti.all_books);

    book_archieve_prefs(ad);
}

// This function prints the all logs and the money of the store.
void Admin_Menu::update_log(Admin ad){
    cout << "------------------------\n";
    cout << "       Update Log       \n";
    cout << "------------------------\n\n";

    cout << "Total income = " << uti.get_library_money() << endl << endl;

    uti.view_update_log();

    cout << endl << endl;

    uti.continue_input();
    admin_screen_switch = 1;

}

// This function takes some input to navigate user. It is a bridge between this home screen and other
// two screens. Which are log screen and archive. It takes an admin object as parameter.
void Admin_Menu::admin_screen_prefs(Admin ad) {

    cout << "\nEnter 'l' to see the update log.\n";
    cout << "      'b' to see the book archieve.\n";
    cout << "      'q' to quit.\n";
    string a;

    while (true){
        getline(cin, a);
        if (a == "l"){
            update_log(ad);
            break;
        }
        else if (a == "b"){
            book_archieve(ad);
            break;
        }
        else if (a == "q"){
            cout << "Quitting the program...\n";
            _sleep(1000);
            uti.update_all_books();
            exit(0);
        }
        else {
            cout << "\nWrong input. Please Try again: ";
            continue;
        }
    }

}

// This function prints a hello screen and calls admin_screen_prefs.
void Admin_Menu::admin_screen(Admin ad){
    cout << "\n-------------------------\n";
    cout << "Hello, Admin " << ad.get_admin_id() <<"! \n";
    cout << "-------------------------\n";

    admin_screen_prefs(ad);
}

// This function calls "check_admin" function to login inputs and control.
// If returned log objects serial number  is -1 then it terminates the program.
// If it is not then transforms log object to admin object and starts program with
// admin_screen panel.
void Admin_Menu::admin_login_inputs(){

    admin_login = check_admin();
    if (admin_login.serial_num != -1){
        cout << "Logged in successfully.\n";
        _sleep(1000);

        admin = get_admin_infos(admin_login);
        admin_screen(admin);
    }
    else {
        string a;
        cout << "Wrong User ID or password. Quitting the program...\n";
        _sleep(1000);
        exit(2);
    }

}

// This is the main function of Admin system. When a state changed it opens the corresponding screen.
void Admin_Menu::start(){


    admin_login_inputs();

    while (true){


        if (admin_screen_switch == 1){
            cout << "Returning back to the admin screen...\n";
            _sleep(1000);
            admin_screen_switch = 0;
            admin_screen(admin);
            continue;
        }

        if (book_archieve_switch == 1){
            cout << "Returning back to the book archieve...\n";
            _sleep(1000);
            book_archieve_switch = 0;
            book_archieve(admin);
            continue;
        }
    }
}