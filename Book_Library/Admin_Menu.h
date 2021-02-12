//------------------------------------------------------------------------
// This class contains the admin interface and core functions of admin system.
// You can check "Admin_Menu.cpp" file to implementation details.
//-------------------------------------------------------------------------
#ifndef BOOK_LIBRARY_ADMIN_MENU_H
#define BOOK_LIBRARY_ADMIN_MENU_H

#include <string>
#include <vector>
#include "Admin.h"

class Admin_Menu {
public:
    void start();
    void admin_login_inputs();
    struct log check_admin();
    Admin get_admin_infos(struct log t);
    void admin_screen(Admin ad);
    void admin_screen_prefs(Admin ad);
    void update_log(Admin ad);
    void book_archieve(Admin ad);
    void book_archieve_prefs(Admin ad);
    void browse_book_as_admin(Admin ad, book current_book);
};
#endif //BOOK_LIBRARY_ADMIN_MENU_H
