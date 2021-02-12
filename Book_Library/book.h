//-----------------------------------------------------------------------------------------------------------
// This class is the one of the most important classes of the program.
// It represents a core data structure of our program. It has eight different
// data field.
// "book_ID" -> Unique for each book. To keep track of the books
// "book_name", "writer", "publisher", "page_number", "price" -> these are the information of th book.
// "liked_number", "read_number" -> these two numbers keep track of the liked number and read number of a certain book.
// For example a book added liked list with three different users than the liked number of that book is three.
// The functions are getters, setters and constructors.
// Recommendation: PLease visit the "User.h" file.
//----------------------------------------------------------------------------------------------------------------
#ifndef BOOK_LIBRARY_BOOK_H
#define BOOK_LIBRARY_BOOK_H

#include <string>
using namespace std;
class book {
private:
    int book_ID;
    string book_name;
    string writer;
    string publisher;
    int page_number;
    float price;
    int liked_number;
    int read_number;
public:
    int getBookId() const;
    void setBookId(int bookId);
    const string &getBookName() const;
    void setBookName(const string &bookName);
    const string &getWriter() const;
    void setWriter(const string &writer);
    const string &getPublisher() const;
    void setPublisher(const string &publisher);
    int getPageNumber() const;
    void setPageNumber(int pageNumber);
    float getPrice() const;
    void setPrice(float price);
    bool compare(book b1);
    book(int I, string n,string w, string p, int pn, float pr, int ln, int rn  );
    book();
    int getLikedNumber() const;
    void setLikedNumber(const int &liked_number);
    int getReadNumber() const;
    void setReadNumber(const int &read_number);
};
#endif //BOOK_LIBRARY_BOOK_H
