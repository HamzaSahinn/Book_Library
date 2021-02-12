
#include <string>
#include "Admin.h"


const string &Admin::get_admin_id() const {
    return admin_ID;
}

void Admin::set_admin_id(const string &ai) {
    admin_ID = ai;
}

const string &Admin::get_password() const {
    return password;
}

void Admin::set_password(const string &p) {
    Admin::password = p;
}

int Admin::get_admin_serial_number() const {
    return admin_serial_number;
}

void Admin::set_admin_serial_number(int asn) {
    admin_serial_number = asn;
}