//---------------------------------------------------------------------
// This is the main function of a E-Library simulation program.
// You can create lists, order books, get book advises and see information
// about the books. I highly recommend that please start examination
// from the "books.h" and "User.h" files. They are the core data structures
// of the program.
// Developers: Sinan Altınayak and Abdullah Hamza Şahin.
//----------------------------------------------------------------------

#include "Utils.h"
#include "Menu.h"

// This is an instance of the "Menu" class. You may see some explanations about this class in "Menu.h" file.
Menu men;
int main() {

    men.start();

    return 0;
}
