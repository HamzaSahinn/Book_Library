//----------------------------------------------------------
// This class contains functions that navigate you to
// register screen, login screen and admin panel.
// You may find brief explanations of these functions in
// "Menu.cpp" file.
// Recommendation: PLease visit the "User_Menu.h" file after finishing this.
//----------------------------------------------------------

#ifndef BOOK_LIBRARY_MENU_H
#define BOOK_LIBRARY_MENU_H


class Menu {
public:

    void start();
    void login_screen();
    void login_screen_prefs();
    void admin_login_inputs();
    void user_login_inputs();
    void go_to_user();
    void go_to_admin();
};


#endif //BOOK_LIBRARY_MENU_H
