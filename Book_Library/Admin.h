//------------------------------------------------------------------------------------------------------------
// This class represents a data structure. The Admin structure is a core data structure for our program.
// It has three data field which are password, ID and serial number. As always serial number is unique for all
// admin users.
//------------------------------------------------------------------------------------------------------------
#ifndef BOOK_LIBRARY_ADMIN_H
#define BOOK_LIBRARY_ADMIN_H

#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Admin {
private:
    string admin_ID;
    string password;
    int admin_serial_number;
public:
    const string &get_admin_id() const;
    void set_admin_id(const string &ai);

    const string &get_password() const;
    void set_password(const string &p);

    int get_admin_serial_number() const;
    void set_admin_serial_number(int asn);
};
#endif //BOOK_LIBRARY_ADMIN_H
